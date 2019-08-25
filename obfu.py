#!/usr/bin/python3

import sys

from vm.program import Program

#----------------------------------------

def main(arg):
    in_file = open(arg,"r")
    out_file = open("out.asm","w")
    p = Program()
    p.input(in_file)
    p.obfuscate()
    p.output(out_file)

#----------------------------------------

if __name__ == '__main__':
    args = sys.argv[1:]
    if len(args) == 0:
        print("Error: missing arguments")
        print("Usage: ./obfu.py file")
        exit(1)
    main(args[0])
