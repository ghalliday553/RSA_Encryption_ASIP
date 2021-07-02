#include "128_Bit_Arithmetic.h"


int main(void) {
	unsigned char binaryBuf1[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf2[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf3[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf4[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf5[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf6[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf7[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf8[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf9[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char binaryBuf10[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	// DECIMAL TO BINARY CONVERSION
	stringToBinary("12345", binaryBuf1);
	printf("12345 binary is: ");
	printArr(binaryBuf1);

	stringToBinary("5678", binaryBuf1);
	printf("5678 binary is: ");
	printArr(binaryBuf1);

	stringToBinary("523", binaryBuf1);
	printf("523 binary is: ");
	printArr(binaryBuf1);

	stringToBinary("340282366920938463463374607431768211455", binaryBuf1);
	printf("340282366920938463463374607431768211455 binary is: ");
	printArr(binaryBuf1);

	stringToBinary("340282366920938463463374607431768211454", binaryBuf1);
	printf("340282366920938463463374607431768211454 binary is: ");
	printArr(binaryBuf1);

	// BINARY STRING ADDITION
	/*
	addBinaryStrings("1", "1", stringBuf);
	printf("Add Strings - 1 + 1 is %s\n", stringBuf);

	addBinaryStrings("10", "1", stringBuf);
	printf("Add Strings - 10 + 1 is %s\n", stringBuf);

	addBinaryStrings("1010", "10", stringBuf);
	printf("Add Strings - 1010 + 10 is %s\n", stringBuf);

	addBinaryStrings("1111", "1", stringBuf);
	printf("Add Strings - 1111 + 1 is %s\n", stringBuf);
	*/


	// BINARY ADDITION
	stringToBinary("2", binaryBuf1);
	stringToBinary("7", binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 10 + 111 is ");
	printArr(binaryBuf3);

	stringToBinary("15", binaryBuf1);
	stringToBinary("15", binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 1111 + 1111 is ");
	printArr(binaryBuf3);

	stringToBinary("15", binaryBuf1);
	stringToBinary("1", binaryBuf2);
	addBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Add Binaries - 1111 + 1 is ");
	printArr(binaryBuf3);


	// BINARY SUBTRACTION
	stringToBinary("25", binaryBuf1);
	stringToBinary("10", binaryBuf2);
	subtractBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Subtract Binaries - 11001 - 1010 is ");
	printArr(binaryBuf3);

	stringToBinary("250", binaryBuf1);
	stringToBinary("15", binaryBuf2);
	subtractBinaries(binaryBuf1, binaryBuf2, binaryBuf3);
	printf("Subtract Binaries - 250 - 15 is ");
	printArr(binaryBuf3);


	// LESS THAN
	stringToBinary("2", binaryBuf1);
	stringToBinary("3", binaryBuf2);
	printf("2 less than 3 ? %i\n", lessThanEqual(binaryBuf1, binaryBuf2));
	printf("3 less than 2 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));

	stringToBinary("3", binaryBuf1);
	printf("3 less than 3 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));

	stringToBinary("5", binaryBuf1);
	stringToBinary("6", binaryBuf2);
	printf("5 less than 6 ? %i\n", lessThanEqual(binaryBuf1, binaryBuf2));
	printf("6 less than 5 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));

	stringToBinary("5", binaryBuf2);
	printf("5 less than 5 ? %i\n", lessThanEqual(binaryBuf2, binaryBuf1));


	// MULTIPLICATION
	stringToBinary("5", binaryBuf1);
	stringToBinary("1024", binaryBuf2);
	stringToBinary("15", binaryBuf3);
	montgomeryMultiplication(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("5*16 mod 15 is ");
	printArr(binaryBuf4);

	stringToBinary("292", binaryBuf1);
	stringToBinary("386", binaryBuf2);
	stringToBinary("667", binaryBuf3);
	montgomeryMultiplication(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	stringToBinary("1", binaryBuf1);
	montgomeryMultiplication(binaryBuf1, binaryBuf4, binaryBuf3, binaryBuf5);
	printf("55*59 mod 667 is ");
	printArr(binaryBuf5);

	stringToBinary("19", binaryBuf1);
	stringToBinary("19", binaryBuf2);
	stringToBinary("35", binaryBuf3);
	montgomeryMultiplication(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	stringToBinary("1", binaryBuf1);
	montgomeryMultiplication(binaryBuf1, binaryBuf4, binaryBuf3, binaryBuf5);
	printf("26*26 mod 35 is ");
	printArr(binaryBuf5);

	stringToBinary("1", binaryBuf1);
	stringToBinary("8", binaryBuf2);
	stringToBinary("9", binaryBuf3);
	montgomeryMultiplication(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	stringToBinary("1", binaryBuf1);
	montgomeryMultiplication(binaryBuf1, binaryBuf4, binaryBuf3, binaryBuf5);
	printf("4*5 mod 9 is ");
	printArr(binaryBuf5);

	stringToBinary("17", binaryBuf1);
	stringToBinary("22", binaryBuf2);
	stringToBinary("23", binaryBuf3);
	montgomeryMultiplication(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("17*22 mod 23 is ");
	printArr(binaryBuf4);

	//MMM Helper
	printf("MMM HELPER ------------\n");

	stringToBinary("55", binaryBuf1);
	stringToBinary("59", binaryBuf2);
	stringToBinary("667", binaryBuf3);
	montgomeryMultiplicationHelper(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("55*59 mod 667 is ");
	printArr(binaryBuf4);

	stringToBinary("26", binaryBuf1);
	stringToBinary("26", binaryBuf2);
	stringToBinary("35", binaryBuf3);
	montgomeryMultiplicationHelper(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("26*26 mod 35 is ");
	printArr(binaryBuf4);

	stringToBinary("4", binaryBuf1);
	stringToBinary("5", binaryBuf2);
	stringToBinary("9", binaryBuf3);
	montgomeryMultiplicationHelper(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("4*5 mod 9 is ");
	printArr(binaryBuf4);

	stringToBinary("127980", binaryBuf1);
	stringToBinary("6428", binaryBuf2);
	stringToBinary("235189", binaryBuf3);
	montgomeryMultiplicationHelper(binaryBuf1, binaryBuf2, binaryBuf3, binaryBuf4);
	printf("127980*6428 mod 235189 is ");
	printArr(binaryBuf4);

	printf("MMM HELPER ------------\n");


	// SHIFT RIGHT
	stringToBinary("17", binaryBuf1);
	shiftRight(binaryBuf1);
	printf("shift 17 right is ");
	printArr(binaryBuf1);

	stringToBinary("523", binaryBuf1);
	shiftRight(binaryBuf1);
	printf("shift 523 right is ");
	printArr(binaryBuf1);



	// BINARY TO DECIMAL
	stringToBinary("55", binaryBuf1);
	size_t ret = binaryToDecimal(binaryBuf1);
	printf("55 is %zu\n", ret);

	stringToBinary("1055", binaryBuf1);
	ret = binaryToDecimal(binaryBuf1);
	printf("1055 is %zu\n", ret);
}





