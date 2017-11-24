.name "dtonc v1.0pl4 V4.2e v0.99pl42Bouh!Bouh!(bruits d'anti-jeu)"
.comment "ta mere elle fait du rodeo sur les kfar :)ge avec des barrieres a l'avant et a l'arriere"

st	r1, 3
st	r1, 3
ld	%100, r4
ld	%4, r6
ld	%0, r3
live	%1
ldi	%0, r3, r2
sti	r2, %-112, r3
add	r3, r6, r3
sub	r3, r4, r5
live	%1
zjmp	%-112
ld	%0, r5
zjmp	%36
