.name "iburel"
.comment "wow"

	ld		%0, r10
osef:
	zjmp	%:debut
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
	st		r1, :osef
	fork	%:octet_4
	live	%2
	fork	%:fin
	live	%2
	ld		%0x0f0f0f0f, r2
	ld		%0, r10

boucle:
	st		r2, :osef + 42
	zjmp	%:boucle

octet_4:
	live	%2
    fork    %:octet_8
    live    %2
    fork    %:octet_12
    live    %2
    ld      %0x0f0f0f01, r12
    ld      %-64, r13
    ld      %0, r10
    zjmp    %:un

octet_8:
    live    %2
    fork    %:octet_16
    live    %2
    st      r1, r12
    ld      %-60, r13
    ld      %0, r10
    zjmp    %:un

octet_12:
    live    %2
    ld      %0x0b540c0d, r12
    ld      %-56, r13
    ld      %0, r10
    zjmp    %:un

octet_16:
    live    %2
    ld      %0x0e09ffbe, r12
    ld      %-52, r13
    ld      %0, r10
    zjmp    %:un

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

deux:
	live	%2
	sti		r12, r13, %:debut + 16
	ld		%0, r10
	zjmp	%:debut - 45

trois:
	live	%2
	fork	%:quatre
	live	%2
	sti		r12, r13, %:debut + 32
	ld		%0, r10
	zjmp	%:debut - 29

quatre:
	live	%2
	sti		r12, r13, %:debut + 48
	ld		%0, r10
	zjmp	%:debut - 13

fin:
