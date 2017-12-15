.name "jmp"
.comment ""

debut:
	live %4
	ld %0, r2
	zjmp %:deux

deux:
	zjmp %:debut
