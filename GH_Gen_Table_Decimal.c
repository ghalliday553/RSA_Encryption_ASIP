#include "128_Bit_Arithmetic.h"

size_t mod = 16157591;

int main(void) {
	FILE *fptr = fopen("./topDecimal.bin","w+");

	size_t byteCounter = 0;
	size_t val = 0;
	while (val <= mod/2) {
		size_t valSqr = (val*val)%mod;
		unsigned char *ptr = (unsigned char*)&valSqr;
		while(byteCounter < ARITHMETIC_BINARY_STORE_LEN) {
			fwrite(ptr+ARITHMETIC_BINARY_STORE_LEN-(1+byteCounter), 1, 1, fptr);
			++byteCounter;
		}
		byteCounter = 0;
		++val;
	}

	fclose(fptr);
}