.name "🎂"
.comment "🎂"

wall:
	ld		%0, r10
	zjmp	%:debut

def:
	live	%2
	ld		%0x0f000000, r2
	ld		%0, r10
	fork	%:boucle2 - 5

boucle1:
	st		r2, -511
	st		r2, -505
	st		r2, -499
	st		r2, -493
	st		r2, -487
	st		r2, -481
	st		r2, -475
	st		r2, -469
	zjmp	%:boucle1

	live	%2
boucle2:
	st		r2, -471
	st		r2, -465
	st		r2, -459
	st		r2, -453
	st		r2, -447
	st		r2, -441
	st		r2, -435
	zjmp	%:boucle2

	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0

debut:
	st		r1, :wall
	st		r1, :octet_8 + 15
	st		r16, -5
	fork	%:def
	live	%2
	fork	%:atk
	live	%2

octet_4:
	fork    %:octet_8
	live    %2
	fork    %:octet_12
	live    %2
	ld      %0x0f0f0f01, r12
	ld      %-72, r13
	ld      %0, r10
	zjmp    %:un - 15

deux:
	live	%2
	sti		r12, r13, %:debut + 16
	ld		%0, r10
	zjmp	%:debut - 53

octet_8:
	live    %2
	fork    %:octet_16
	live    %2
	ld      %2, r12
	ld      %-68, r13
	ld      %0, r10
	zjmp    %:un - 15

octet_12:
	live    %2
	ld      %0x0b540c0d, r12
	ld      %-64, r13
	ld      %0, r10
	zjmp    %:un - 15

octet_16:
	live    %2
	ld      %0x0e09ffb6, r12
	ld      %-60, r13
	ld      %0, r10
	zjmp    %:un - 15

trois:
	live	%2
	fork	%:quatre
	live	%2
	sti		r12, r13, %:debut + 32
	ld		%0, r10
	zjmp	%:debut - 37

	st		r1, :octet_4
	st		r1, :un + 1
	st		r16, -5
	
un:
	live	%2
	fork	%:un
	live	%2
	fork	%:trois
	live	%2
	fork	%:deux
	live	%2
	sti		r12, r13, %:debut
	ld		%0, r10
	zjmp	%:debut - 69

atk:
	live	%2
	ld		%507, r6
	ld		%8, r8
	fork	%:sjmp

vite:
	live	%2
	ld		%4, r2
	ld		%0x060901f6, r3
	ld		%0x060901f7, r5
	ld		%0x00040000, r7
	ld		%0, r16
	zjmp	%:rush

quatre:
	live	%2
	sti		r12, r13, %:debut + 48
	ld		%0, r10
	zjmp	%:debut - 21

sjmp:
	live	%2
	ld		%0, r2
	ld		%0x0b540502, r3
	ld		%0x0b540702, r5
	ld		%0x08037007, r7
	ld		%0, r16
	zjmp	%:rush

rush:
	sti		r3, r2, r6
	zjmp	%0x01f6
