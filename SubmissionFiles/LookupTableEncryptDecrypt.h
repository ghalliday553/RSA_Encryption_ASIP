#include "APIntegerLibrary.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void encrypt_decrypt(const unsigned char *num, const unsigned char *exp, const unsigned char *mod, unsigned char *out)
{
	memset(out, 0, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char halfMod[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	memcpy(halfMod, mod, ARITHMETIC_BINARY_BUFF_LEN);
	shiftRight(halfMod);

	// Open lookup table file
	FILE *fptr = fopen("./LookupTable.bin", "r");

	// Initialize buffer to max value
	char maxSize[30] = {0};
	snprintf(maxSize, 30, "%u", UINT32_MAX);
	unsigned char max[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	stringToBinary(maxSize, max);

	// Allocate and initialize temporary buffers
	unsigned char square[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	memcpy(square, num, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char product[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	stringToBinary("1", product);

	// Other initialisation
	register size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	register unsigned short bitMask = 1;

	register size_t expBits = ARITHMETIC_BINARY_BUFF_LEN * 8 - bitOffset(exp);
	register size_t bitCounter = 0;

	while ((!((bitCounter == expBits) || (byteInd == 0))))
	{
		// Loop through each byte
		if (bitMask > 128) {
			bitMask = 1;
			--byteInd;
		}
		/*
		 *	If exponent bit is a 1, multiply running product with the next square 
		 */
		if (exp[byteInd] & bitMask) {
			unsigned char mult[ARITHMETIC_BINARY_BUFF_LEN] = {0};
			multiplication(square, product, mult);

			unsigned char divRes[ARITHMETIC_BINARY_BUFF_LEN] = {0};
			division(mult, mod, divRes);

			unsigned char multRes[ARITHMETIC_BINARY_BUFF_LEN] = {0};
			multiplication(mod, divRes, multRes);

			subtraction(mult, multRes, out);

			memcpy(product, out, ARITHMETIC_BINARY_BUFF_LEN);
		}

		//instead of an extra branch to function
		if (lessThanEqual(square, halfMod) <= 0) {
			unsigned char distanceFromCenterBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
			unsigned char oneBuff[ARITHMETIC_BINARY_BUFF_LEN] = {0};
			unsigned char tempBuff[ARITHMETIC_BINARY_BUFF_LEN] = {0};
			stringToBinary("1", oneBuff);

			subtraction(square, halfMod, distanceFromCenterBuf);
			subtraction(halfMod, distanceFromCenterBuf, tempBuff);
			addition(tempBuff, oneBuff, square);
		}

		/*
		 *	If file offset is greater than UINT32_MAX, loop until 
		 *	remaining offset is uneer UINT32_MAX
		 */
		fseek(fptr, 0, SEEK_SET);
		while (lessThanEqual(max, square) >= 0) {
			subtraction(square, max, product);
			memcpy(square, product, ARITHMETIC_BINARY_BUFF_LEN);
			register int i;
			for (i ^= i; i < ARITHMETIC_BINARY_STORE_LEN; i++)
			{
				fseek(fptr, SIZE_MAX, SEEK_CUR);
			}
		}

		/*
		 * Convert the lookup table byte offset into a decimal size_t and 
		 * increment the file pointer accordingly.
		 */
		register size_t offset = binaryToDecimal(square);
		if (offset < UINT32_MAX / ARITHMETIC_BINARY_BUFF_LEN) {
			fseek(fptr, offset * ARITHMETIC_BINARY_STORE_LEN, SEEK_CUR);
		}

		/*
		 * The value being stored at index n is the square of index n.
		 * Update square with the next square.
		 */
		fread(square + ARITHMETIC_BINARY_STORE_LEN + (ARITHMETIC_BINARY_BUFF_LEN % ARITHMETIC_BINARY_STORE_LEN),
			  ARITHMETIC_BINARY_STORE_LEN, 1, fptr);

		bitMask <<= 1;
		++bitCounter;

	}

	fclose(fptr);
}
