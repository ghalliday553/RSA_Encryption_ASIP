#include "APIntegerLibrary.h"

// 16-bit key
char mod[ARITHMETIC_STRING_BUFF_LEN] = "59989";

int main(void) {
	unsigned char valueBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char counterBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char modBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char resultBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char oneBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char twoBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	stringToBinary("0", valueBuf);

	// Constants to be frequently used
	stringToBinary("1", oneBuf);
	stringToBinary("2", twoBuf);

	stringToBinary(mod, modBuf);

	FILE *fptr = fopen("./LookupTable.bin","w+");

	while (lessThanEqual(counterBuf, modBuf) == 1) {
		// Calculate the square of the index
		montgomeryMultiplicationHelper(valueBuf, valueBuf, modBuf, resultBuf);

		// Write the result to file
		fwrite(resultBuf+ARITHMETIC_BINARY_STORE_LEN+(ARITHMETIC_BINARY_BUFF_LEN%ARITHMETIC_BINARY_STORE_LEN), sizeof(unsigned char), ARITHMETIC_BINARY_STORE_LEN, fptr);

		// Increment index
		addition(valueBuf, oneBuf, resultBuf);
		memcpy(valueBuf, resultBuf, ARITHMETIC_BINARY_BUFF_LEN);

		// Increment counter
		addition(counterBuf, twoBuf, resultBuf);
		memcpy(counterBuf, resultBuf, ARITHMETIC_BINARY_BUFF_LEN);
	}

	fclose(fptr);
}