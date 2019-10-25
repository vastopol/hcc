.text
.globl main
jal main
li $v0, 10
syscall

main:
sub $sp, $sp, 4
sw $ra, 4($sp)
sub $sp, $sp, 4
li $t0, 100
sw $t0, 4($sp)
lw $a0, 4($sp)
li $v0, 1
syscall
add $sp, $sp, 4
li $v0, 0
lw $ra, 4($sp)
add $sp, $sp, 4
jr $ra

