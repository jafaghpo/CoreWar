.name "pas de stress"
.comment "ya point s ta compris ou pas
nique les weebs"

ld %0, r10

bite:
	fork %:deux
	live %0
	fork %:trois
	live %0
	ld %4294967295, r4
	ld %16, r5
	ld %0, r6
	zjmp %:suite
	
deux:
	live %0
	fork %:quatre
	live %0
	ld %84149761, r4
	ld %12, r5
	ld %0, r6
	zjmp %:suite

trois:
	live %0
	ld %190055429, r4
	ld %10, r5
	or r10, r10, r10
	aff r10
	aff r10
	ld %0, r6
	zjmp %:suite

quatre:
	live %0
	ld %1234567, r4
	ld %400, r5
	ld %0, r6
	zjmp %:suite

suite:
	sti r4, r5, r6
	live %4294967295
