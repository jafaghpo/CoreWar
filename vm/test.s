
.name "testos"
.comment "franchement styler"

debut:
	live	%-90
	ld		54, r1
	ld		%145, r2
	aff		r2
	st		r2, 100
	ld		%0, r15
	zjmp	%:debut

mdr:
	aff		r3
	ld		%0, r10
	zjmp	%0
