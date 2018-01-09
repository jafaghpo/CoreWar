.name "test"
.comment ""

debub:
	ld	%0, r1
	zjmp %:fin
	ld %100, r2
	ld %100, r2
	ld %100, r2


fin:
	live %214744458

