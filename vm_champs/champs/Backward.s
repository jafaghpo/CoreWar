.name "sebc"
.comment "sebc"

st        r1,   13
ld        %4,   r3
live      %1
ld        %-40,   r2
ldi       %28,   r2,   r4
sti       r4,   %65458,   r2
add       r2,   r3,   r2
zjmp      %65407
xor       r4,   r4,   r4
zjmp      %65511
