#!/bin/bash

# compile, optimize, strip, and pack with upx

gcc -O3 -static $1
strip a.out
upx a.out


