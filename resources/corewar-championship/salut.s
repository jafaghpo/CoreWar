.name "iburel"
.comment "wow"

octet_4:
    fork    %:octet_8
    live    %2
    fork    %:octet_12
    live    %2
    ld      %252645121, r12
    ld      %-128, r13
    ld      %0, r10
    zjmp    %:un

octet_8:
    live    %2
    fork    %:octet_16
    live    %2
    st      r1, r12
    ld      %-124, r13
    ld      %0, r10
    zjmp    %:un

octet_12:
    live    %2
    ld      %190057485, r12
    ld      %-120, r13
    ld      %0, r10
    zjmp    %:un

octet_16:
    live    %2
    ld      %235536254, r12
    ld      %-116, r13
    ld      %0, r10
    zjmp    %:un

un:
	live	%2
	fork	%:un
	live	%2
	fork	%:cinq
	live	%2
	fork	%:trois
	live	%2
	fork	%:deux
	live	%2
	sti		r12, r13, %:octet_4
	ld		%0, r10
	zjmp	%:octet_4-125

deux:
	live	%2
	sti		r12, r13, %:octet_4 + 16
	ld		%0, r10
	zjmp	%:octet_4 - 109

trois:
	live	%2
	fork	%:quatre
	live	%2
	sti		r12, r13, %:octet_4 + 32
	ld		%0, r10
	zjmp	%:octet_4 - 93

quatre:
	live	%2
	sti		r12, r13, %:octet_4 + 48
	ld		%0, r10
	zjmp	%:octet_4 - 77

cinq:
	live	%2
	fork	%:sept
	live	%2
	fork	%:six
	live	%2
	sti		r12, r13, %:octet_4 + 64
	ld		%0, r10
	zjmp	%:octet_4 - 61

six:
	live	%2
	sti		r12, r13, %:octet_4 + 80
	ld		%0, r10
	zjmp	%:octet_4 - 45

sept:
	live	%2
	fork	%:huit
	live	%2
	sti		r12, r13, %:octet_4 + 96
	ld		%0, r10
	zjmp	%:octet_4 - 29

huit:
	live	%2
	sti		r12, r13, %:octet_4 + 112
	ld		%0, r10
	zjmp	%:octet_4 - 13
