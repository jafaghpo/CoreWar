
.name "testos"
.comment "franchement styler"

ld %0, r3
ld %1, r4

debut:
	live	%-90
	add r3, r4, r3 
	ld %0, r2
	fork %:mdr
	zjmp	%:debut

mdr:
	st r3, 100
	fork %0
	fork %0
	fork %0
	fork %0
	fork %0
	fork %0
	fork %0
	fork %0
	fork %0
