#include "128_Bit_Arithmetic.h"


int main(void) {
	char stringBuf[ARITHMETIC_STRING_BUFF_LEN] = {0};
	unsigned char binaryBuf1[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf2[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf3[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf4[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	// DECIMAL TO BINARY CONVERSION
	stringToBinary("12345", stringBuf, binaryBuf1);
	printf("12345 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBinary("5678", stringBuf, binaryBuf1);
	printf("5678 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBinary("523", stringBuf, binaryBuf1);
	printf("523 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBinary("340282366920938463463374607431768211455", stringBuf, binaryBuf1);
	printf("340282366920938463463374607431768211455 - binary str is %s, binary is ", stringBuf);
	printArr(binaryBuf1);

	stringToBinary("340282366920938463463374607431768211454", stringBuf, binaryBuf1);
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
	stringToBinary("2", stringBuf, binaryBuf1);
	stringToBinary("7", stringBuf, binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 10 + 111 is ");
	printArr(binaryBuf3);

	stringToBinary("15", stringBuf, binaryBuf1);
	stringToBinary("15", stringBuf, binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 1111 + 1111 is ");
	printArr(binaryBuf3);

	stringToBinary("15", stringBuf, binaryBuf1);
	stringToBinary("1", stringBuf, binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 1111 + 1 is ");
	printArr(binaryBuf3);


	// BINARY SUBTRACTION
	stringToBinary("25", stringBuf, binaryBuf1);
	stringToBinary("10", stringBuf, binaryBuf2);
	subtractBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Subtract Binaries - 11001 - 1010 is ");
	printArr(binaryBuf3);

	stringToBinary("250", stringBuf, binaryBuf1);
	stringToBinary("15", stringBuf, binaryBuf2);
	subtractBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Subtract Binaries - 250 - 15 is ");
	printArr(binaryBuf3);


	// LESS THAN
	stringToBinary("2", stringBuf, binaryBuf1);
	stringToBinary("3", stringBuf, binaryBuf2);
	printf("2 less than 3 ? %i\n", lessThanEqual(binaryBuf1, binaryBuf2));
	printf("3 less than 2 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));

	stringToBinary("3", stringBuf, binaryBuf1);
	printf("3 less than 3 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));

	stringToBinary("5", stringBuf, binaryBuf1);
	stringToBinary("6", stringBuf, binaryBuf2);
	printf("5 less than 6 ? %i\n", lessThanEqual(binaryBuf1, binaryBuf2));
	printf("6 less than 5 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));

	stringToBinary("5", stringBuf, binaryBuf2);
	printf("5 less than 5 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));


	// MULTIPLICATION
	stringToBinary("17", stringBuf, binaryBuf1);
	stringToBinary("22", stringBuf, binaryBuf2);
	stringToBinary("23", stringBuf, binaryBuf3);
	montgomeryMultiplication(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("17*22 mod 23 is ");
	printArr(binaryBuf4);

	// SHIFT RIGHT
	stringToBinary("17", stringBuf, binaryBuf1);
	shiftRight(binaryBuf1);
	printf("shift 17 right is ");
	printArr(binaryBuf1);

	stringToBinary("523", stringBuf, binaryBuf1);
	shiftRight(binaryBuf1);
	printf("shift 523 right is ");
	printArr(binaryBuf1);

}