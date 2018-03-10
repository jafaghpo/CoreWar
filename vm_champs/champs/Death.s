.name "Death"
.comment "Fork"

st        r1,   146
st        r1,   146
st        r1,   146
st        r1,   146
st        r1,   49
st        r1,   89
xor       r2,   r2,   r2
fork      %83
ld        %-15,   r3
ld        %1,   r4
add       r3,   r4,   r3
zjmp      %11
xor       r5,   r5,   r5
zjmp      %65523
live      %1
ld        %-25,   r3
ld        %1,   r4
add       r3,   r4,   r3
zjmp      %11
xor       r5,   r5,   r5
zjmp      %65523
xor       r1,   r1,   r1
add       r1,   r1,   r1
live      %1
fork      %3
fork      %3
fork      %3
fork      %3
fork      %3
fork      %3
fork      %3
fork      %3
fork      %3
live      %1
live      %1
live      %1
live      %1
zjmp      %65516
