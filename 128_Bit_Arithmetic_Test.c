#include "128_Bit_Arithmetic.h"

void printArr(unsigned char* ptr) {
	for (int i = 0; i<ARITHMETIC_BINARY_BUFF_LEN; i++) {
		printf("%x", ptr[i]);
	}
	printf("\n");
}


int main(void) {
	char stringBuf[ARITHMETIC_STRING_BUFF_LEN] = {0};
	unsigned char binaryBuf1[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf2[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf3[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	// DECIMAL TO BINARY CONVERSION
	stringToBits("12345", stringBuf, binaryBuf1);
	printf("12345 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBits("5678", stringBuf, binaryBuf1);
	printf("5678 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBits("340282366920938463463374607431768211455", stringBuf, binaryBuf1);
	printf("340282366920938463463374607431768211455 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBits("340282366920938463463374607431768211454", stringBuf, binaryBuf1);
	printf("340282366920938463463374607431768211454 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	// BINARY STRING ADDITION
	addBinaryStrings("1", "1", stringBuf);
	printf("Add Strings - 1 + 1 is %s\n", stringBuf);

	addBinaryStrings("10", "1", stringBuf);
	printf("Add Strings - 10 + 1 is %s\n", stringBuf);

	addBinaryStrings("1010", "10", stringBuf);
	printf("Add Strings - 1010 + 10 is %s\n", stringBuf);

	addBinaryStrings("1111", "1", stringBuf);
	printf("Add Strings - 1111 + 1 is %s\n", stringBuf);


	// BINARY ADDITION
	stringToBits("2", stringBuf, binaryBuf1);
	stringToBits("7", stringBuf, binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 10 + 111 is ");
	printArr(binaryBuf3);

	stringToBits("15", stringBuf, binaryBuf1);
	stringToBits("15", stringBuf, binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 1111 + 1111 is ");
	printArr(binaryBuf3);

	stringToBits("15", stringBuf, binaryBuf1);
	stringToBits("1", stringBuf, binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 1111 + 1 is ");
	printArr(binaryBuf3);
}