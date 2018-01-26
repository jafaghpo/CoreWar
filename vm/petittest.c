#include <stdio.h>
#include <emmintrin.h>

void print128(__m128i value) {
	int64_t *v64 = (int64_t*) &value;
	printf("%.16llx %.16llx\n", v64[1], v64[0]);
}

int main() {
	__m128i a = _mm_setr_epi32(0x00ffff00, 0x00ffff00, 0x00ffff00, 0x10ffff00), /* low dword first! */
			b = _mm_setr_epi32(0x0000ffff, 0x0000ffff, 0x0000ffff, 0x0000ffff),
			x;

	asm (
			"movdqa %1, %%xmm0;"      /* xmm0 <- a */
			"movdqa %2, %%xmm1;"      /* xmm1 <- b */
			"pxor %%xmm1, %%xmm0;"    /* xmm0 <- xmm0 xor xmm1 */
			"movdqa %%xmm0, %0;"      /* x <- xmm0 */

			:"=x"(x)          /* output operand, %0 */
			:"x"(a), "x"(b)   /* input operands, %1, %2 */
			:"%xmm0","%xmm1"  /* clobbered registers */
		);

	/* printf the arguments and result as 2 64-bit hex values */
	print128(a);
	print128(b);
	print128(x);
}
