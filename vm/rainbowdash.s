.name	"zaz"
.comment "rainbowdash"

ld %0, r2
ld %4, r3
ld %8, r4
ld %16, r5
ld %32, r6
ld %0, r10
zjmp %:debu
j1:
zjmp    %:un
j2:
zjmp    %:deu
j3:
zjmp    %:troi
j4:
zjmp    %:quatr
debu:
live    %1
fork    %:debu
live    %1
fork    %:j1
add     r2, r6, r2
add     r15, r15, r15
un:
live    %1
fork    %:j2
add     r2, r5, r2
add     r15, r15, r15
deu:
live    %1
fork    %:j3
add     r2, r4, r2  
add     r15, r15, r15
troi:
live    %1
fork    %:j4
add     r2, r3, r2
add     r15, r15, r15
quatr:
live    %8
ldi     %13, r2, r16
ld      %0, r15
sti     r16, %64, r2
sti     r16, %122, r2
sti     r16, %180, r2
sti     r16, %238, r2
sti     r16, %298, r2
sti     r16, %357, r2
live    %42
live    %42
sti     r16, %297, r2
sti     r16, %448, r2
zjmp    %442
live    %42
