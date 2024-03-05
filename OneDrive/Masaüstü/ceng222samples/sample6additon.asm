
.data
number1: .word 10
number2: .word 15

.text
lw $t0, number1($zero)
lw $t1, number2($zero)
add  $t2 , $t1 , $t0 #t2=t1+t0

li $v0 ,1
add $a0,$zero,$t2

syscall 
#adding numbers 



