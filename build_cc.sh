#!/bin/bash

FOLDER="cc"
FILES="tests"
COMP="cc/compiler"
MILR="sim/mil_run"

#----------------------------------------

function main()
{
    if [ "$1" == "-c" ] ; then
        clean_up
        exit 0
    fi

    build_cc; echo
    # test_cc
}

#----------------------------------------

function build_cc()
{
    echo
    echo "Making compiler:"
    echo

    cd $FOLDER
    make
    cd ..
}

#----------------------------------------

# compile and run custom tests
function test_cc()
{
    echo
    echo "Testing compiler:"
    echo

    $COMP $FILES/test_comp.min > test_comp.min.mil

    cat test_comp.min.mil;
    echo

    $MILR test_comp.min.mil <<< '1 2 3 4 5 6 7' # there are 7 reads in the test file

    # compile and run custom tests
    echo
    echo "Testing Errors:"
    echo

    $COMP $FILES/err_comp1.min > err_comp1.min.mil
    $COMP $FILES/err_comp2.min > err_comp2.min.mil
    $COMP $FILES/err_comp3.min > err_comp3.min.mil

    cat err_comp1.min.mil;
    echo

    cat err_comp2.min.mil;
    echo

    cat err_comp3.min.mil;
    echo

    # compile the standard test files: fibonacci, mytest, primes
    # run generated code from the standard test files against mil interpreter

    echo
    echo "Compiling files:"
    echo

    for i in $(ls $FILES | grep \.min)
    do
        echo $i".mil"
        $COMP $FILES/$i > $i".mil"
    done

    echo
    echo "Testing files:"
    echo

    for i in $(ls | grep \.min.mil)
    do
        echo $i
        $MILR $i <<< '10 5' # mytest.min has 2 reads
        echo
    done
}

#----------------------------------------

# remove generated files from build
function clean_up()
{
    echo
    echo "Clean up:"
    echo

    rm *.ir *.asm

    rm -rf vm/__pycache__

    cd $FOLDER
    make clean
    cd ..

    echo
}

#----------------------------------------

# MAIN
main "$@"
