.data
PI: .float   3.145


.text
li $v0,2
lwc1  $f12,PI
syscall 
#printing a float value
