.data

.text
addi $t0, $zero, 18   
addi $t1, $zero, 9    
div $t0, $t1          

mflo $s0              


li $v0, 1             
move $a0, $s0         
syscall              
