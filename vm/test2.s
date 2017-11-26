.name "test2"
.comment "d"

debut:
	ld %3735924751, r1
	fork %:suite
	ld %0, r2
	zjmp %:debut

suite:
	st r1, 100
	suite2: zjmp %0
