.name "🎂"
.comment "🎂 je suis gros et je mange des gateaux 🎂"

wall:
	ld		%0, r10
	zjmp	%:debut

def:
	live	%2
	ld		%0x0f000000, r2
	ld		%0, r10
	fork	%:boucle2 - 5
	live	%2

boucle1:
	st		r2, -511
	st		r2, -508
	st		r2, -505
	st		r2, -502
	st		r2, -499
	st		r2, -496
	st		r2, -493
	st		r2, -490
	zjmp	%:boucle1

	live	%2
boucle2:
	st		r2, -495
	st		r2, -492
	st		r2, -489
	st		r2, -486
	st		r2, -483
	st		r2, -480
	st		r2, -477
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
	ld      %-64, r13
	ld      %0, r10
	zjmp    %:un - 15

deux:
	live	%2
	sti		r12, r13, %:debut + 16
	ld		%0, r10
	zjmp	%:debut - 45

octet_8:
	live    %2
	fork    %:octet_16
	live    %2
	ld      %2, r12
	ld      %-60, r13
	ld      %0, r10
	zjmp    %:un - 15

octet_12:
	live    %2
	ld      %0x0b540c0d, r12
	ld      %-56, r13
	ld      %0, r10
	zjmp    %:un - 15

octet_16:
	live    %2
	ld      %0x0e09ffbe, r12
	ld      %-52, r13
	ld      %0, r10
	zjmp    %:un - 15

trois:
	live	%2
	fork	%:quatre
	live	%2
	sti		r12, r13, %:debut + 32
	ld		%0, r10
	zjmp	%:debut - 29

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
	zjmp	%:debut - 61

atk:
	live	%2
	ld		%507, r6
	ld		%8, r8
	fork	%:sjmp

sst:
	live	%2
	ld		%0, r2
	ld		%0x0b540502, r3
	ld		%0x0b540702, r5
	ld		%0x0b540702, r7
	ld		%0, r16
	zjmp	%:rush

quatre:
	live	%2
	sti		r12, r13, %:debut + 48
	ld		%0, r10
	zjmp	%:debut - 13

sjmp:
	live	%2
	ld		%4, r2
	ld		%0x060901f6, r3
	ld		%0x060901f6, r5
	ld		%0x08000000, r7
	ld		%0, r16
	zjmp	%:rush

rush:
	sti		r3, r2, r6
	zjmp	%0x01f6
