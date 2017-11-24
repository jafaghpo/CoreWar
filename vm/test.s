.name "testos"
.comment "franchement styler"

debut:
	live	%-90
	ld		54, r1
	ld		%0x45, r2
	aff		r2
	st		r2, 100
	ld		%0, r15
	fork	%500
	zjmp	%:debut

mdr:
	ld		%0x42, r3
	aff		r3
	ld		%0, r10
	zjmp	%0
