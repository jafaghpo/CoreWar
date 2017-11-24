.name	"zaz"
.comment "rainbowdash"

ld      %0x40, r7
ld      %0x20, r6
ld      %0x10, r5
ld      %0x08, r4
ld      %0x04, r3
st      r1, 0x01a8
st      r16, 0xfffc
st      r1, 0x01b0
st      r16, 0xfffc
st      r1, 0x01b8
st      r16, 0xfffc
st      r1, 0x01c0
st      r16, 0xfffc
st      r1, 0x0178
st      r16, 0xfffc
st      r1, 0x0049
st      r16, 0xfffc
st      r1, 0x0037
st      r16, 0xfffc
ld      %0, r15
st      r1, 0x01d4
st      r16, 0xfffc
st      r1, 0x01cf
st      r16, 0xfffc
fork    %0x013e
ld      %0, r2
ld      %0, r16
live    %42
fork    %0xfffb
live    %0x4acdc7
st      r2, 0xffdf
st      r2, 0xffd6
st      r2, 0xffcd
st      r2, 0xffc4
st      r2, 0xffbb
st      r2, 0xffb2
st      r2, 0xffa9
st      r2, 0xffa0
st      r2, 0xff97
st      r2, 0xff8e
st      r2, 0xff85
st      r2, 0xff7c
st      r2, 0xff73
st      r2, 0xff6a
st      r2, 0xff61
st      r2, 0xff58
st      r2, 0xff4f
st      r2, 0xff46
st      r2, 0xff3d
st      r2, 0xff34
st      r2, 0xff2b
st      r2, 0xff22
st      r2, 0xff19
st      r2, 0xff10
st      r2, 0xff07
st      r2, 0xfffe
st      r2, 0xfff5
st      r2, 0xffec
st      r2, 0xffe3
st      r2, 0xffda
st      r2, 0xffd1
st      r2, 0xffc8
st      r2, 0xffbf
st      r2, 0xffb6
st      r2, 0xffad
st      r2, 0xffa4
st      r2, 0xff9b
st      r2, 0xff92
st      r2, 0xff89
st      r2, 0xff80
st      r2, 0xff77
st      r2, 0xff6e
st      r2, 0xff65
st      r2, 0xff5c
st      r2, 0xff53
st      r2, 0xff4a
st      r2, 0xff41
st      r2, 0xff38
st      r2, 0xff2f
st      r2, 0xff26
st      r2, 0xff1d
st      r2, 0xff14
st      r2, 0xff0b
st      r2, 0xff02
zjmp    %0xfeed
zjmp    %0x0017
zjmp    %0x0026
zjmp    %0x0035
zjmp    %0x0044
zjmp    %0x0053
live    %1
fork    %0xfffb
live    %1
fork    %0xffe7
add     r2, r6, r2
add     r15, r15, r15
live    %1
fork    %0xffd8
add     r2, r5, r2
add     r15, r15, r15
live    %1
fork    %0xffc9
add     r2, r4, r2
add     r15, r15, r15
live    %1
fork    %0xffba
add     r2, r3, r2
add     r15, r15, r15
ldi     %0x0d, r2, r16
ld      %0, r15
sti     r16, %0x40, r2
sti     r16, %0x7a, r2
sti     r16, %0xb4, r2
sti     r16, %0xee, r2
sti     r16, %0x128, r2
sti     r16, %0x162, r2
live    %42
live    %42
sti     r16, %0x192, r2
sti     r16, %0x1c0, r2
zjmp    %0x01ba
live    %42