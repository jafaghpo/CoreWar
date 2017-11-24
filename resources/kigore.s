.name "🎂"
.comment "🎂"

debut:
	st		r1, :prog + 37
	st		r16, -5
    fork    %:salut2
    or      r2, %0b1000000, r2

salut2:
    live    %2
    fork    %:salut3
    or      r2, %0b0100000, r2

salut3:
    live    %2
    fork    %:salut4
    or      r2, %0b0010000, r2

salut4:
    live    %2
    fork    %:salut5
    or      r2, %0b0001000, r2

salut5:
    live    %2
    fork    %:salut6
    or      r2, %0b0000100, r2

salut6:
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
