.name "dtonc v1.0pl2 V4.2e v0.99pl42Bouh!Bouh!(bruits d'anti-jeu)"
.comment "ta mere elle fait du rodeo sur les kfar :)ge avec des barrieres a l'avant et a l'arriere"

ld	%15, r3
ld	%-61, r4
ld	%0, r7
ld	%589824, r8
live	%1
fork	%28
ld	%0, r5
fork	%65
live	%1
fork	%115
live	%1
fork	%-89
zjmp	%28
live	%1
zjmp	%65
live	%1
fork	%73
live	%1
sti	r8, %-66, r2
add	r2, r3, r2
sub	r4, r2, r5
zjmp	%115
ld	%0, r5
zjmp	%81
ld	%0, r2
zjmp	%81
live	%1
fork	%125
live	%1
sti	r7, %0, r2
sub	r2, r3, r2
add	r4, r2, r5
zjmp	%-89
ld	%0, r5
zjmp	%-123
ld	%0, r2
zjmp	%-123
live	%0
xor	r1, r1, r5
zjmp	%-79
xor	r1, r1, r1
