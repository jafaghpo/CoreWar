.name "dtonc v1.0pl2"
.comment "ta mere elle fait du rodeo sur les kfar"

ld        %15,   r3
ld        %195,   r4
ld        %0,   r7
ld        %589824,   r8
live      %1
fork      %65531
ld        %0,   r5
fork      %22
live      %1
fork      %22
live      %1
fork      %66
zjmp      %65502
live      %1
zjmp      %65531
live      %1
fork      %65531
live      %1
sti       r8,   %104,   r2
add       r2,   r3,   r2
sub       r4,   r2,   r5
zjmp      %13
ld        %0,   r5
zjmp      %65505
ld        %0,   r2
zjmp      %65495
live      %1
fork      %65531
live      %1
sti       r7,   %65398,   r2
sub       r2,   r3,   r2
add       r4,   r2,   r5
zjmp      %13
ld        %0,   r5
zjmp      %65505
ld        %0,   r2
zjmp      %65495
live      %0
xor       r1,   r1,   r5
zjmp      %65526
xor       r1,   r1,   r1
