.data
age: .word   23

#this is just a comment line to show what it is 
.text
li $v0,1
lw $a0,age
syscall 