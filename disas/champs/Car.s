.name "Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)"
.comment "sebc a basic Winner Program"

fork	%106
ld	%-16, r3
live	%0
fork	%62
ld	%-16, r3
fork	%45
ld	%0, r2
ld	%0, r4
zjmp	%-75
ld	%4, r2
ld	%0, r4
zjmp	%-75
ld	%-202, r3
fork	%89
ld	%0, r2
ld	%0, r4
zjmp	%-23
ld	%4, r2
ld	%0, r4
zjmp	%-23
ld	%-112, r3
live	%0
fork	%-98
fork	%-115
ld	%0, r2
ld	%0, r4
zjmp	%-49
ld	%4, r2
ld	%0, r4
zjmp	%-49
fork	%-85
ld	%0, r4
zjmp	%3
ld	%0, r4
zjmp	%14
ldi	r2, %-57, r6
ld	%0, r4
live	%1
sti	r6, r2, r3
zjmp	%-21
ldi	r2, %-31, r6
ld	%0, r4
live	%1
sti	r6, r2, r3
zjmp	%-117
ldi	r2, %-5, r6
ld	%0, r4
live	%1
sti	r6, r2, r3
zjmp	%-207
live	%1
fork	%259
zjmp	%259
live	%1
fork	%270
zjmp	%270
