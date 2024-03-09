.data
message: .asciiz "hello world it is allright there"

.text
main:
    jal displayMessage  

  
    li $s0, 15

   
    li $v0, 1
    move $a0, $s0      
    syscall

    
    li $v0, 10
    syscall

displayMessage:
    # Print the message
    li $v0, 4
    la $a0, message
    syscall

    jr $ra
