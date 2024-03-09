
.data
number1: .word 10
number2: .word 15

.text
lw $s0, number1
lw $s1, number2
sub  $t0 , $s1 , $s0 #t0=s1-s0

li $v0 ,1
move  $a0,$t0

syscall 
#substracting  numbers 
