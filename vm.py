#!/usr/bin/python3

import sys
import copy

# ----------------------------------------

class Program():

    def __init__(self):
        self.buffer = list()
        self.functions = dict()

    def input(self,ifile):
        for i in ifile:
            k = [ j.strip() for j in i.split(' ') ]
            l = list( filter( lambda x: x is not '' , k ) )
            if l != list():
                self.buffer.append(l)

    def output(self,ofile):
        head = ".text\njal main\nli $v0, 10\nsyscall\n\n"  # stub for jump to main
        ofile.write(head)
        for f in self.functions:
            for g in self.functions[f]:
                ofile.write(str(g)+"\n")    # here gen code...
            ofile.write("\n")

    def obfuscate(self):
        """
        read in the ir file
        spliting instructions into a 2d list
        by opcode translate to mips
        between each good instruction insert garbage instructions
        keep data variables on the stack
        """

        fname = ""
        code = list()
        data = list()

        # separate code and data
        for b in self.buffer:
            if   b[0] == "func":
                fname = b[1]
                code.append(b)
            elif b[0] == "endfunc":
                code.append(b)
                self.functions[fname] = code
                # self.functions[fname] = [code[0]] + data + code[1:]
                fname = ""
                code = list()
                data = list()
                continue
            elif b[0] == "." or b[0] == ".[]":  # data declaration
                data.append(b)
            elif b[0] == "=":   # immediate constants, int
                if b[2].isdigit():
                    code.append(b)
            elif b[0] == "param" or b[0] == "ret":  # skip this
                continue
            else:
                code.append(b)

# ----------------------------------------

def main(arg):
    in_file = open(arg,"r")
    out_file = open("out.asm","w")
    p = Program()
    p.input(in_file)
    p.obfuscate()
    p.output(out_file)

# ----------------------------------------

if __name__ == '__main__':
    args = sys.argv[1:]
    if len(args) == 0:
        print("Error: missing arguments")
        print("Usage: ./vm.py file")
        exit(1)
    main(args[0])
