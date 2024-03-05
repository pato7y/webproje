.data
myDouble: .double   3.145757575575
zeroDouble: .double 0.000


.text
ldc1 $f2,myDouble
ldc1 $f0,zeroDouble



li $v0,3

add.d $f12,$f2,$f0
syscall 