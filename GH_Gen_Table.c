#include "128_Bit_Arithmetic.h"

char mod[10] = "3233";

int main(void) {
	unsigned char valueBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char modBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char resultBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char oneBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	stringToBinary("0", valueBuf);
	stringToBinary("1", oneBuf);
	stringToBinary(mod, modBuf);

	FILE *fptr = fopen("./top.bin","w+");
	while (lessThanEqual(valueBuf, modBuf) == 1) {
		// Calculate the square of the index
		montgomeryMultiplicationHelper(valueBuf, valueBuf, modBuf, resultBuf);

		// Write the result to file
		fwrite(resultBuf+ARITHMETIC_BINARY_STORE_LEN, sizeof(unsigned char), ARITHMETIC_BINARY_STORE_LEN, fptr);

		// Increment index
		addBinaries(valueBuf, oneBuf, resultBuf);
		memcpy(valueBuf, resultBuf, ARITHMETIC_BINARY_BUFF_LEN);
	}

	fclose(fptr);
}