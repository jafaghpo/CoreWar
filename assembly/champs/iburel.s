.name "iburel"
.comment "viiiiite"

	ld		%1, r3
	ld		%4, r4
	ld		%0x02d00000, r6
	ld		%400, r12
	fork	%:prog + 7

live:
	st		r1, 6
	live	%2
	st		r6, -10
	ld		%0, r10
	zjmp	%:live

prog:
	fork	%:ouais
	ld		%400, r11
	ld		%0, r10
	zjmp	%:super

ouais:
	ld		%-400, r11

super:
	ld		%30, r7
	ld		%-69, r5

boucle:
	st		r1, 6
	live	%2
	and		r5, %0xffff, r8
	or		r6, r8, r9
	st		r9, 5
	ld		2, r10
	sti		r10, r5, r11
	add		r5, r4, r5
	sub		r7, r3, r7
	zjmp	%:next
	ld		%0, r10
	zjmp	%:boucle

next:
	sub		r11, r12, r13
	zjmp	%288
	ld		%0, r10
	zjmp	%-498
