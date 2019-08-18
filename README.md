# hcc

hacker's compiler collection (hcc)

This project is still in the idea stage.

## Goals

* Compiler tool chain for constructing obfuscated binaries
* Library of different obfuscation techniques which can be used together.
* Support for binary level instrumentation: rewriting, patching, hardening.

## Summary

Initial prototypes may be created first, but eventually this should be done as a plugin to an existing mature project.

The project should consist of 2 separate parts which operate under one interface.
One component will focus on source code level transformations and obfuscation methods.
The other component will focus on binary level patching and instrumentation.

Most likely the source code transformation will be written as a special LLVM pass.
Hopefully the individual methods can each be separately implemented as tree transformations.
This would allow the obfuscator to operate on a higher level intermediate representation.
This also would leverage the existing intermediate representation of the LLVM tool chain,
allowing it to be used with with any compiler front end which can produce the respective IR code.

The binary instrumentation and patching
This can be used on non obfuscated binary executables to produce equivalent obfuscated ones.
This will also allow vulnerable programs to be patched or modified to improve security.
This should include support for both detour jump patching and reassembly as well.
Hopefully existing disassemblers and binary analysis platforms can serve as an implementation guide.


Possible Hardening/Obfuscation/Anti-reversing techniques:
* Control Flow Graph Flattening
* Packing
* Encryption
* Anti Debug
* Shadow Stack
* Junk Code
* Opaque Predicates

## PROTOTYPE

recycling a simple compiler for now.

have the stage 1 simple compiler output code for a vm
the stage 2 vm will then output the assembly code probably mips

stack based vm obfuscation for variables
so no variables in registers, but everything on the stack
try between each good instruction insert garbage instructions
turn branches into 2 way je and jne pairs to the same label
rename functions

maybe

$sp: temp variables on stack, parameters to functions

maybe have the parameters all be pushed on stack,
when function gets called pop all parameters into s registers
temp valus should exist on stack in the sp
the t registers can be used for the temporary stuff math etc
after use t registers push back to stack

maybe

count params then push a integer to the v1 register
the function when called has to check v1 and see how many args to pop from the stack


 * stack
    So if you use this to push $t2:

    sub $sp,$sp,4
    sw $t2,($sp)

    You would pop $t2 with:

    lw $t2,($sp)
    addiu $sp,$sp,4

* calls

    # function enter

    sub $sp,$sp,4
    sw $ra,4($sp)

    # function exit

    lw $ra,4($sp) # pop ra
    add $sp,$sp,4
    jr $ra # return


    # prologue
    sw $fp -8($sp)
    move $fp $sp
    subu $sp $sp <size of args>
    sw $ra -4($fp)
    ...
    # epilogue
    lw $ra -4($fp)
    lw $fp -8($fp)
    addu $sp $sp <size of args>
    jr $ra