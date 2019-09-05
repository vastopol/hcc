# Program representation during the transform from IR to ASM

import boltons.iterutils    # need: boltons.iterutils.chunked()

class Program():

    def __init__(self):
        self.buffer    = list()  # initial ir for program
        self.functions = dict()  # ir function blocks
        self.assembly  = dict()  # assembly instructions for functions

    #----------------------------------------

    # read in the IR code file
    def input(self,ifile):
        for i in ifile:
            k = [ j.strip() for j in i.split(' ') ]
            l = list( filter( lambda x: x is not '' , k ) )
            if l != list():
                self.buffer.append(l)

    #----------------------------------------

    # write out the MIPS assembly code file
    def output(self,ofile):
        stub = ".text\n.globl main\njal main\nli $v0, 10\nsyscall\n\n"  # stub for jump to main
        ofile.write(stub)
        for f in self.assembly:
            for g in self.assembly[f]:
                ofile.write(str(g))
            ofile.write("\n")

    #----------------------------------------

    # wrapper around the internal obfuscation steps
    def obfuscate(self):
        """
        1. Split and Process IR
        2. Translate into MIPS
        """
        self.split_ir()
        self.minimize_ir()
        self.translate_ir()

    #----------------------------------------

    # break up and reorganize IR
    def split_ir(self):
        name = str()
        data = list()
        code = list()

        # separating code and data
        for b in self.buffer:
            if b[0] == "func":
                name = b[1]
                code.append(b)
            elif b[0] == "endfunc":
                code.append(b)
                data_set = list()
                for d in data:
                    if d not in data_set:
                        data_set.append(d)
                self.functions[name] = [code[0]] + data_set + code[1:]
                name = ""
                code = list()
                data = list()
                continue
            elif b[0] == ".":    # int declaration
                data.append(b)
            elif b[0] == ".[]":  # array declaration
                data.append(b)
            else:
                code.append(b)

    #----------------------------------------

    # minimize the IR before translation
    def minimize_ir(self):
        # self.print_ir()
        # print('-'*40+'\n')
        self.minimize1() # assign assign
        self.minimize2() # read assign
        self.minimize3() # assign param
        self.minimize4() # call assign
        self.minimize5() # op assign
        self.minimize6() # var propagate
        self.minimize7() # params -- pass 1
        self.minimize7() # params -- pass 2
        self.print_ir()
    #----------------------------------------

    # assign assign
    def minimize1(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()
            gcode = boltons.iterutils.chunked(ecode,2)

            for g in gcode:
                if g[0][0] == "=" and g[1][0] == "=":  # 2 assigns in a row: t0 = x; t1 = t0
                    if str(g[0][1])[:-1] == str(g[1][2]):
                        if str(g[1][1])[0] == '_':  # only remove temps (_T...)
                            remline.append(g[1])
                            remvars[ str(g[1][1])[:-1] ] = g[1][2]

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # read assign
    def minimize2(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()
            gcode = boltons.iterutils.chunked(ecode,2)

            for g in gcode:
                if g[0][0] == ".<" and g[1][0] == "=":  # read assign: .< x; = t0, x
                    if str(g[0][1]) == str(g[1][2]):
                        if str(g[1][1])[0] == '_':  # only remove temps (_T...)
                            remline.append(g[1])
                            remvars[ str(g[1][1])[:-1] ] = g[0][1]

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # assign param
    def minimize3(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()
            gcode = boltons.iterutils.chunked(ecode,2)

            for g in gcode:
                if g[0][0] == "=" and g[1][0] == "param":  # param assign: t0 = x; param t0
                    if str(g[0][1])[:-1] == str(g[1][1]):
                        if str(g[1][1])[0] == '_':  # only remove temps (_T...)
                            remline.append(g[1])
                            remvars[ str(g[1][1])[:-1] ] = g[1][1]

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # call assign
    def minimize4(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()
            gcode = boltons.iterutils.chunked(ecode,2)

            for g in gcode:
                if g[0][0] == "call" and g[1][0] == "=":  # call assign: t0 = call f; t1 = t0
                    if str(g[0][2]) == str(g[1][2]):
                        if str(g[1][2])[0] == '_':  # only remove temps (_T...)
                            remline.append(g[1])
                            remvars[ str(g[0][2]) ] = g[1][1][:-1]

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # op assign
    def minimize5(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()
            gcode = boltons.iterutils.chunked(ecode,2)

            for g in gcode:
                if len(g[0]) == 4 and g[1][0] == "=":  # op assign: t2 = op(t0,t1) f; t3 = t2
                    if str(g[0][1])[:-1] == str(g[1][2]):
                        if str(g[1][1])[0] == '_':  # only remove temps (_T...)
                            remline.append(g[1])
                            remvars[ str(g[1][1])[:-1] ] = str(g[0][1])[:-1]

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # var propagate
    def minimize6(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()

            for g in ecode:
                if g[0] == "=" and str(g[2]).isdigit():  # int
                        remline.append(g)
                        remvars[ str(g[1])[:-1] ] = str(g[2])
                elif g[0] == "=" and str(g[2])[0] is '_':
                        remline.append(g)
                        remvars[ str(g[1])[:-1] ] = str(g[2])

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # params
    def minimize7(self):
        for foo in self.functions:
            fname = foo
            fhead = self.functions[foo][0]
            ftail = self.functions[foo][-1]
            fcode = self.functions[foo][1:-1]

            ecode = list()
            for fuu in fcode:
                if fuu[0] == ".":
                    continue
                else:
                    ecode.append(fuu)

            remline = list()
            remvars = dict()

            for g in ecode:
                if g[0] == "=" and str(g[2])[0] is '$':
                        remline.append(g)
                        remvars[ str(g[1])[:-1] ] = str(g[2])

            # print(); [ print(r) for r in remline ]; print()
            # print(); [ print(r) for r in remvars ]; print()

            hcode = list()
            icode = list()

            for f in fcode:
                if f in remline:
                    continue
                else:
                    hcode.append(f)

            for h in hcode:
                line = h
                for r in remvars:
                    if r in line or r+',' in line:
                        if h[0] == ".":  # discard the declarations
                            line = None
                            break
                        for p in range(len(h)):
                            if h[p] == r:
                                line[p] = remvars[r]
                                break
                            elif h[p] == r+',':
                                line[p] = remvars[r]+','
                                break
                if line:
                    icode.append(line)

            minifun = [fhead] + icode + [ftail]
            self.functions[foo] = minifun

    #----------------------------------------

    # (depth)*4        for word sizes
    # (depth+1)*4      for return address
    # ((depth+1)+$#)*4 for stack params

    # translate IR to MIPS
    def translate_ir(self):
        bin_ops = ["+", "-", "*", "/", "%", "==", "!=", ">", ">=", "<", "<=", "&&", "||"]
        for f in self.functions:
            fname = f
            asm = list()
            locals = dict()  # name and offset into the stack pointer
            depth  = 1       # depth into stack
            for g in self.functions[f]:
                # begin function
                if g[0] == "func":
                    header  = g[1] + ":\n"
                    push_ra = "sub $sp, $sp, 4\nsw $ra, 4($sp)\n"  # push $ra
                    asm.append(header + push_ra)
                # end function
                elif g[0] == "endfunc":
                    if fname == "main":  # main has no ret
                        add_sp = "add $sp, $sp, 4\n"
                        for i in range(depth-1):
                            asm.append(add_sp)
                        rval   = "li $v0, 0\n"
                        pop_ra = "lw $ra, 4($sp)\nadd $sp, $sp, 4\n"   # pop $ra
                        ret    = "jr $ra\n"
                        asm.append(rval + pop_ra + ret)
                    self.assembly[fname] = asm
                # locals
                elif g[0] == "." or g[0] == ".[]":
                    locals[g[1]] = depth
                    depth += 1
                    sub_sp  = "sub $sp, $sp, 4\n"
                    asm.append(sub_sp)
                # function call
                elif g[0] == "call":
                    call = "jal " + g[1][:-1] + "\n"
                    push_i  = "sw $v0, " + str( locals[g[2]]*4 ) + "($sp)\n"   # push $v0
                    asm.append(call + push_i)
                # function return
                elif g[0] == "ret":
                    pop_i = str()
                    if str(g[1]).isdigit():  # immediate int
                        pop_i  = "li $v0, " + g[1] + "\n"  # pop $v0
                    else:
                        pop_i  = "lw $v0, " + str( locals[g[1]]*4 ) + "($sp)\n"  # pop $v0
                    add_i = "add $sp, $sp, 4\n"
                    pop_ra = "lw $ra, 4($sp)\nadd $sp, $sp, 4\n"   # pop $ra
                    ret    = "jr $ra\n"
                    asm.append(pop_i)
                    for i in range(depth-1):  # stack vars
                        asm.append(add_i)
                    asm.append(pop_ra + ret)
                # label
                elif g[0] == ":":
                    label = g[1] + ":\n"
                    asm.append(label)
                # goto
                elif g[0] == ":=":
                    goto = "j " + g[1] + "\n"
                    asm.append(goto)
                # branch
                elif g[0] == "?:=":
                    t0 = locals[g[2]]*4
                    pop_i  = "lw $t0, " + str(t0) + "($sp)\n"
                    branch = "bne $t0, $zero, " + g[1][:-1] + "\n"
                    asm.append(pop_i + branch)
                # math/logic
                elif g[0] in bin_ops:
                    t0 = str(); t1 = str(); t2 = str()
                    pop_i_a = str(); pop_i_b = str();
                    op_i = str();
                    push_i = str()

                    # dest
                    if g[1][:-1] in locals:
                        t0 = locals[g[1][:-1]]*4
                        push_i  = "sw $t0, " + str(t0) + "($sp)\n"

                    # src 1
                    if g[2][:-1] in locals:
                        t1 = locals[g[2][:-1]]*4
                        pop_i_a = "lw $t1, " + str(t1) + "($sp)\n"
                    elif (g[2][:-1])[0] == "$":
                        t1 = ( (len(locals)+1)+1 + int((g[2][:-1])[1:]) )*4
                        pop_i_a = "lw $t1, " + str(t1) + "($sp)\n"
                    elif str(g[2][:-1]).isdigit():
                        pop_i_b = "li $t1, " + str(g[2][:-1]) + "\n"

                    # src 2
                    if g[3] in locals:
                        t2 = locals[g[3]]*4
                        pop_i_b = "lw $t2, " + str(t2) + "($sp)\n"
                    elif g[3][0] == "$":
                        t2 = ( (len(locals)+1)+1 + int((g[3])[1:]) )*4
                        pop_i_b = "lw $t2, " + str(t2) + "($sp)\n"
                    elif str(g[3]).isdigit():
                        pop_i_b = "li $t2, " + str(g[3]) + "\n"

                    # add
                    if g[0] == "+":
                        op_i   = "add $t0, $t1, $t2\n"
                    # sub
                    elif g[0] == "-":
                        op_i   = "sub $t0, $t1, $t2\n"
                    # mul
                    elif g[0] == "*":
                        pass
                    # div
                    elif g[0] == "/":
                        pass
                    # mod
                    elif g[0] == "%":
                        pass
                    # eq
                    elif g[0] == "==":
                        op_i   = "seq $t0, $t1, $t2\n"
                    # neq
                    elif g[0] == "!=":
                        op_i   = "sne $t0, $t1, $t2\n"
                    # lt
                    elif g[0] == "<":
                        op_i   = "slt $t0, $t1, $t2\n"
                    # lte
                    elif g[0] == "<=":
                        op_i   = "sle $t0, $t1, $t2\n"
                    # gt
                    elif g[0] == ">":
                        op_i   = "sgt $t0, $t1, $t2\n"
                    # gte
                    elif g[0] == ">=":
                        op_i   = "sge $t0, $t1, $t2\n"
                    asm.append(pop_i_b + pop_i_a + op_i + push_i)
                # print int (syscall 1)
                elif g[0] == ".>":
                    pop_i   = "lw $a0, " + str( locals[g[1]]*4 ) + "($sp)\n"  # pop $a0
                    print_i = "li $v0, 1\nsyscall\n"
                    asm.append(pop_i + print_i)
                # read int (syscall 5)
                elif g[0] == ".<":
                    read_i = "li $v0, 5\nsyscall\n"
                    push_i = "sw $v0, " + str( locals[g[1]]*4 ) + "($sp)\n"   # push $v0
                    asm.append(read_i + push_i)
                # immediate int
                # elif g[0] == "=":
                #     if g[2].isdigit():
                #         imm_i  = "li $t0, " + g[2] + "\n"
                #         push_i = "sub $sp, $sp, 4\nsw $t0, ($sp)\n" # push $t0
                #         asm.append(imm_i + push_i)

    #----------------------------------------

    # debug/info
    def print_ir(self):
        for f in self.functions:
            foo = str()
            for g in self.functions[f]:
                s = str()
                for h in g:
                    s = s + str(h) + ' '
                s = s[:-1]  # rm last space, errors for mil_run interpreter
                s += '\n'
                if g[0] != "func" and g[0] != "endfunc" and g[0] != ":":
                    s = '\t' + s
                foo += s
            print(foo)

    #----------------------------------------
