#include "128_Bit_Arithmetic.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void formatOffset(unsigned char *square, const unsigned char *halfMod) {
	if (lessThanEqual(square, halfMod) <= 0){
		unsigned char distanceFromCenterBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char oneBuff[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char tempBuff[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		stringToBinary("1", oneBuff);

		subtractBinaries(square, halfMod, distanceFromCenterBuf);
		subtractBinaries(halfMod, distanceFromCenterBuf, tempBuff);
		addBinaries(tempBuff, oneBuff, square);
	}
}

void encrypt_decrypt(const unsigned char *num, const unsigned char *exp, const unsigned char *mod, unsigned char* out) {
	memset(out, 0, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char halfMod[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	memcpy(halfMod, mod, ARITHMETIC_BINARY_BUFF_LEN);
	shiftRight(halfMod);

	FILE *fptr = fopen("./topDecimal.bin","r");

	// Initialize buffer to max size_t value
	char maxSize[30] = {0};
	snprintf(maxSize, 30, "%zu", SIZE_MAX);
	unsigned char max[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	stringToBinary(maxSize, max);

	// Allocate and initialize temporary buffers
	unsigned char square[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	memcpy(square, num, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char product[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	stringToBinary("1", product);

	// Other initialisation
	size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	bool carry = false;
	unsigned short bitMask = 1;

	size_t expBits = ARITHMETIC_BINARY_BUFF_LEN*8 - bitOffset(exp);
	size_t bitCounter = 0;

	// Loop until byteInd is 0
	while (1) {
		// Loop through each byte
		while (bitMask <= 128) {
			/*
			 * Exit if all non-0 exp bits have been used 
			 */
			if (bitCounter == expBits) {
				break;
			}

			/*
			 *	If exponent bit is a 1, multiply running product with the next square 
			 */
			if(exp[byteInd] & bitMask){
				montgomeryMultiplicationHelper(product, square, mod, out);
				memcpy(product, out, ARITHMETIC_BINARY_BUFF_LEN);
			}

			formatOffset(square, halfMod);

			/*
			 *	If file offset is greater than SIZE_MAX, loop until 
			 *	remaining offset is uneer SIZE_MAX
			 */
			fseek(fptr, 0, SEEK_SET);
			while(lessThanEqual(max, square) >= 0){
				subtractBinaries(square, max, product);
				memcpy(square, product, ARITHMETIC_BINARY_BUFF_LEN);
				for (int i = 0; i < ARITHMETIC_BINARY_STORE_LEN; i++) {
					fseek(fptr, SIZE_MAX, SEEK_CUR);
				}
			}

			/*
			 * Convert the lookup table byte offset into a decimal size_t and 
			 * increment the file pointer accordingly.
			 */
			size_t offset = binaryToDecimal(square);
			if(offset < SIZE_MAX/ARITHMETIC_BINARY_BUFF_LEN) {
				fseek(fptr, offset*ARITHMETIC_BINARY_STORE_LEN, SEEK_CUR);
			} else {
				for (int i = 0; i < ARITHMETIC_BINARY_STORE_LEN; i++) {
					fseek(fptr, offset, SEEK_CUR);
				}
			}

			/*
			 * The value being stored at index n is the square of index n.
			 * Update square with the next square.
			 */
			fread(square+ARITHMETIC_BINARY_STORE_LEN, ARITHMETIC_BINARY_STORE_LEN, 1, fptr);

			bitMask <<= 1;
			++bitCounter;
		}

		bitMask = 1;
		if(byteInd == 0 || bitCounter == expBits) {
			break;
		} else {
			--byteInd;
		}
	}

	fclose(fptr);
}