.data
myMessage: .asciiz "my firs message"

.text
li $v0,4
la $a0,myMessage
syscall 