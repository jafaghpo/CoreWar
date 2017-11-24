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
	st		r16, -5
	st		r1, :prog + 37
	st		r16, -5
	fork	%:def
	live	%2
	fork	%:aaaaah
	live	%2

apocalypse:
	fork	%:apocalypse - 5
	live	%2
    fork    %:salut2
    or      r2, %0b100000, r2

salut2:
    live    %2
    fork    %:salut3
    or      r2, %0b010000, r2

salut3:
    live    %2
    fork    %:salut4
    or      r2, %0b001000, r2

salut4:
    live    %2
    fork    %:salut5
    or      r2, %0b000100, r2

salut5:
    ldi     %:prog, r2, r16
    ld      %0, r15

prog:
    sti     r16, %0x40, r2
    sti     r16, %0x7a, r2
    sti     r16, %0xb4, r2
    sti     r16, %0xee, r2
    sti     r16, %0x128, r2
    sti     r16, %0x162, r2
    live    %2
    live    %2
    sti     r16, %0x192, r2
    sti     r16, %0x1c0, r2
    zjmp    %0x01ba
    live    %2

aaaaah:
	live	%2
	ld		%507, r6
	ld		%8, r8
	ld		%139, r10
	fork	%:sjmp

vite:
	live	%2
	ld		%4, r2
	ld		%0x060901f6, r3
	ld		%0x060901f6, r5
	ld		%0x0a090087, r7
	ld		%0x00040000, r9
	ld		%0, r16
	zjmp	%:rush

sjmp:
	live	%2
	ld		%0, r2
	ld		%0x0b540502, r3
	ld		%0x0b540702, r5
	ld		%0x0b540902, r7
	ld		%0x08037009, r9
	ld		%0, r16
	zjmp	%:rush

rush:
	sti		r3, r2, r6
	zjmp	%0x01f6
