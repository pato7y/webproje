
.data

.text
addi $s0,$zero,10
addi $s1,$zero,5

#   addi $s2,$zero,400
 # addi $s3,$zero,30
# addi $s3,$zero,3
#sll $t0 ,$s0,2

mul $t0,$s0,$s1

# mult $t1,$t2 
# mflo $s0 



#printing the result
li $v0 ,1
add $a0,$zero,$t0

# li $v0,1
# add $a0,$zero,$t0



syscall 
#multiplication of  numbers 

