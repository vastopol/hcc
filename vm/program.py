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
        data = list()  # not used yet
        code = list()

        # separating code and data
        for b in self.buffer:
            if b[0] == "func":
                name = b[1]
                code.append(b)
            elif b[0] == "endfunc":
                code.append(b)
                self.functions[name] = [code[0]] + data + code[1:]
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
        self.print_ir()
        self.minimize1() # assign assign
        self.minimize2() # read assign
        self.minimize3() # assign param
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
                        print('a')
                        if str(g[1][1])[0] == '_':  # only remove temps (_T...)
                            print('b')
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

    # translate IR to MIPS
    def translate_ir(self):
        fname = str()
        asm = list()

        # translating
        for f in self.functions:
            fname = f
            for g in self.functions[f]:
                # begin function
                if g[0] == "func":
                    header  = g[1] + ":\n"
                    # pop params into the s regs ??
                    push_ra = "sub $sp, $sp, 4\nsw $ra, 4($sp)\n"  # push $ra
                    asm.append(header + push_ra)
                # end function
                elif g[0] == "endfunc":
                    if fname == "main":  # main has no ret
                        rval   = "li $v0, 0\n"
                        pop_ra = "lw $ra, 4($sp)\nadd $sp, $sp, 4\n"   # pop $ra
                        ret    = "jr $ra\n"
                        asm.append(rval + pop_ra + ret)
                    self.assembly[fname] = asm
                    fname = ""
                    asm = list()
                    continue
                # function call
                elif g[0] == "call":
                    call = "jal " + g[1][:-1] + "\n"
                    push_i  = "sub $sp, $sp, 4\nsw $v0, ($sp)\n"   # push $v0
                    asm.append(call + push_i)
                elif g[0] == "ret":
                    pop_i  = "lw $v0, ($sp)\naddiu $sp, $sp, 4\n"  # pop $v0
                    pop_ra = "lw $ra, 4($sp)\nadd $sp, $sp, 4\n"   # pop $ra
                    ret    = "jr $ra\n"
                    asm.append(pop_i + pop_ra + ret)
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
                    pop_i  = "lw $t0, ($sp)\naddiu $sp, $sp, 4\n"   # pop $t0
                    branch = "bne $t0, $zero " + g[1][:-1] + "\n"
                    asm.append(pop_i + branch)
                # add
                elif g[0] == "+":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    add_i   = "add $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + add_i + push_i)
                # sub
                elif g[0] == "-":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "sub $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
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
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "seq $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
                # neq
                elif g[0] == "!=":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "sne $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
                # lt
                elif g[0] == "<":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "slt $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
                # lte
                elif g[0] == "<=":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "sle $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
                # gt
                elif g[0] == ">":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "sgt $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
                # gte
                elif g[0] == ">=":
                    pop_i_b = "lw $t2, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t2
                    pop_i_a = "lw $t1, ($sp)\naddiu $sp, $sp, 4\n"  # pop $t1
                    sub_i   = "sge $t0, $t1, $t2\n"
                    push_i  = "sub $sp, $sp, 4\nsw $t0, ($sp)\n"    # push $t0
                    asm.append(pop_i_b + pop_i_a + sub_i + push_i)
                # read int (syscall 5)
                elif g[0] == ".<":
                    read_i = "li $v0, 5\nsyscall\n"
                    push_i = "sub $sp, $sp, 4\nsw $v0, ($sp)\n"     # push $v0
                    asm.append(read_i + push_i)
                # print int (syscall 1)
                elif g[0] == ".>":
                    pop_i   = "lw $a0, ($sp)\naddiu $sp, $sp, 4\n"  # pop $a0
                    print_i = "li $v0, 1\nsyscall\n"
                    asm.append(pop_i + print_i)
                # immediate int
                elif g[0] == "=":
                    if g[2].isdigit():
                        imm_i  = "li $t0, " + g[2] + "\n"
                        push_i = "sub $sp, $sp, 4\nsw $t0, ($sp)\n" # push $t0
                        asm.append(imm_i + push_i)

    #----------------------------------------

    # debug info
    def print_ir(self):
        for f in self.functions:
            for g in self.functions[f]:
                print(g)
            print()

    #----------------------------------------
