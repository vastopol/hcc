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

