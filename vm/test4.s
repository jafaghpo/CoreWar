.name "testos 4"
.comment "celui la il jump"

code:
	live %42			
	live %42			
	live %42			
	live %42			

debut:
	ld %5, r14
	add r13, r14, r13
	sti r1, %:code, %1
	sti r1, %:code, %6
	sti r1, %:code, %11
	sti r1, %:code, %16
	ld %5, r9
	add r2, r3, r4
	live %852
	zjmp %:plutar
	ld %61, r5
	aff r5

plutar:
	ld %10, r5
	add r9, r5, r6
truc:
	ld :truc, r9
	sti r9, r13, %2000
	sub r12, r12, r12
	zjmp %:code
