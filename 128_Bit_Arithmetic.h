#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define ARITHMETIC_STRING_BUFF_LEN 200
#define ARITHMETIC_BINARY_BUFF_LEN 5
#define ARITHMETIC_BINARY_STORE_LEN (ARITHMETIC_BINARY_BUFF_LEN / 2)

void printArr(const unsigned char *ptr)
{
	register int i;
	for (i = 0; i < ARITHMETIC_BINARY_BUFF_LEN; i++)
	{
		printf("%02x", ptr[i]);
	}
	printf("\n");
}

/*
 * Helper function for stringToBits()
 */
void divStringByTwo(char *buf)
{
	register int add = 0;
	char *it;
	for (it = buf; *it != '\0'; ++it)
	{
		int digit = *it - '0';
		digit /= 2;
		digit += add;
		switch (*it)
		{
		case '1':
		case '3':
		case '5':
		case '7':
		case '9':
			add = 5;
			break;
		default:
			add = 0;
			break;
		}
		*it = digit + '0';
	}

	int zeroOffset = 0;
	for (it = buf; *it == '0'; ++it)
	{
		++zeroOffset;
	}
	memmove(buf, buf + zeroOffset, strlen(buf) - zeroOffset + 1);
}

/*
 * Converts a string of decimal numbers to both its binary string and binary equivalents
 *
 * Input: inputBuf
 *	- Input string consisting of a decimal number of arbitrary size
 *
 * Output: stringOutputBuf, binaryOutputBuf
 *	- Output buffers where the equivalent binary string and binary representations are written
 *
 * Note: stringOutputBuf and binaryOutputBuf must be large enough to hold the largest needed numbers.
 * 		 Their sizes must be defined using ARITHMETIC_STRING_BUFF_LEN and ARITHMETIC_BINARY_BUFF_LEN.
 */
bool stringToBinary(const char *inputBuf, unsigned char *outputBuf)
{
	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	char stringTempBuf[ARITHMETIC_STRING_BUFF_LEN] = {0};

	register size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	register unsigned int bitMask = 1;

	strcpy(stringTempBuf, inputBuf);

	while (strlen(stringTempBuf))
	{
		switch (stringTempBuf[strlen(stringTempBuf) - 1])
		{
		case '1':
		case '3':
		case '5':
		case '7':
		case '9':
			outputBuf[byteInd] |= bitMask;
			break;
		default:
			break;
		}
		divStringByTwo(stringTempBuf);
		bitMask <<= 1;

		if (bitMask > 128)
		{
			bitMask = 1;
			--byteInd;
		}
	}

	return true;
}

/*
 * Computes the sum of two binary numbers
 *
 * Input: operand1, operand2
 *	- Input buffers holding binary numbers.
 *
 * Output: outputBuf
 *	- Output buffer where the sum is written to
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must defined by ARITHMETIC_BINARY_BUFF_LEN.
 */
bool addition(const unsigned char *operand1, const unsigned char *operand2, unsigned char *outputBuf)
{

	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	register size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	register bool carry = false;
	register unsigned int binaryBitMask = 1;

	while (!(byteInd == 0))
	{
		//while (binaryBitMask <= 128) {
		if (binaryBitMask > 128)
		{ //force in line
			binaryBitMask = 1;
			--byteInd;
		}
		if ((binaryBitMask & operand1[byteInd]) >= 1 && (binaryBitMask & operand2[byteInd]) >= 1)
		{
			if (carry)
			{
				outputBuf[byteInd] |= binaryBitMask;
			}
			carry = true;
		}
		else if ((binaryBitMask & operand1[byteInd]) >= 1 || (binaryBitMask & operand2[byteInd]) >= 1)
		{
			if (carry)
			{
				carry = true;
			}
			else
			{
				outputBuf[byteInd] |= binaryBitMask;
				carry = false;
			}
		}
		else
		{
			if (carry)
			{
				outputBuf[byteInd] |= binaryBitMask;
			}
			carry = false;
		}

		binaryBitMask <<= 1;

	} //end of while (1)
	return true;
}

/*
 * Subtracts one binary number from another
 *
 * Input: operand1, operand2
 * 	- Operand 2 is subtracted from operand 1
 * 	- Behavior is undefinded if operand 2 is greater than operand 1
 *
 * Output: outputBuf
 *	- Output buffer where the result is written to
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must defined by ARITHMETIC_BINARY_BUFF_LEN.
 */
bool subtraction(const unsigned char *operand1, const unsigned char *operand2, unsigned char *outputBuf)
{
	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	register size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	register bool borrow = false;
	register unsigned int binaryBitMask = 1;

	while (!(byteInd == 0))
	{
		if (binaryBitMask > 128)
		{ //force in line
			binaryBitMask = 1;
			--byteInd;
		}

		if ((binaryBitMask & operand1[byteInd]) >= 1 && (binaryBitMask & operand2[byteInd]) >= 1)
		{
			if (borrow)
			{
				outputBuf[byteInd] |= binaryBitMask;
			}
		}
		else if ((binaryBitMask & operand1[byteInd]) >= 1 && (binaryBitMask & operand2[byteInd]) == 0)
		{
			if (borrow)
			{
				borrow = false;
			}
			else
			{
				outputBuf[byteInd] |= binaryBitMask;
			}
		}
		else if ((binaryBitMask & operand1[byteInd]) == 0 && (binaryBitMask & operand2[byteInd]) >= 1)
		{
			if (!borrow)
			{
				outputBuf[byteInd] |= binaryBitMask;
			}
			borrow = true;
		}
		else
		{
			if (borrow)
			{
				outputBuf[byteInd] |= binaryBitMask;
			}
		}
		binaryBitMask <<= 1;

	} //end of while (1)
	return true;
}

/*
 * Computes operand 1 is less than or equal to operand 2.
 *
 * Input: operand1, operand2
 *
 * Output: return value
 *	- +1 if operand1 < operand2
 * 	- -1 if operand1 > operand2
 * 	- 0 if operand1 == operand2
 */
int lessThanEqual(const unsigned char *operand1, const unsigned char *operand2)
{
	register unsigned int bitMask = 128;
	register size_t byteInd = 0;

	while (byteInd < ARITHMETIC_BINARY_BUFF_LEN)
	{

		if (bitMask < 1)
		{ //force in line check
			bitMask = 128;
			++byteInd;
		}

		if ((operand1[byteInd] & bitMask) && !(operand2[byteInd] & bitMask))
		{
			return -1;
		}
		else if ((operand2[byteInd] & bitMask) && !(operand1[byteInd] & bitMask))
		{
			return 1;
		}
		bitMask >>= 1;
	}
	return 0;
}

/*
 * Shifts the binary number right by 1 in place
 *
 * Input/Output: operand1
 */
bool shiftRight(unsigned char *operand1)
{
	register size_t byteInd = 0;
	register unsigned char newTemp = 0;
	register unsigned char prevTemp = 0;

	while (byteInd < ARITHMETIC_BINARY_BUFF_LEN)
	{
		prevTemp = newTemp;
		newTemp = (operand1[byteInd] & 1);
		operand1[byteInd] >>= 1;
		operand1[byteInd] |= (prevTemp << 7);

		++byteInd;
	}
	return true;
}

/*
 * Computes the number of bits before the first non-zero bit
 *
 * Input: operand1
 *
 * Output: return value
 *	- number of bits
 */
size_t bitOffset(const unsigned char *operand1)
{
	register size_t byteInd = 0;
	register unsigned int bitMask = 128;

	register size_t bitOffset = 0;
	while (!(byteInd == ARITHMETIC_BINARY_BUFF_LEN))
	{

		if (operand1[byteInd] != 0x0)
		{

			while (bitMask >= 1)
			{

				if ((bitMask & operand1[byteInd]) != 0x0)
				{
					return bitOffset;
				} //end of if

				bitMask >>= 1;
				++bitOffset;

			} //end of bitMask

			bitMask = 128;
		} //end of if
		bitOffset += 8;
		++byteInd;
	} // end of whilw

	return ARITHMETIC_BINARY_BUFF_LEN * 8;
}

/*
 * Shifts the binary number left by 1 in place
 *
 * Input/Output: operand1
 */
bool shiftLeft(unsigned char *operand1)
{
	register size_t byteInd = bitOffset(operand1) / 8 - 1;
	while (byteInd < ARITHMETIC_BINARY_BUFF_LEN - 1)
	{
		operand1[byteInd] <<= 1;
		operand1[byteInd] |= (operand1[byteInd + 1] >> 7);
		++byteInd;
	}
	operand1[ARITHMETIC_BINARY_BUFF_LEN - 1] <<= 1;

	return true;
}

/*
 * Computes the multiplication of operand1 and operand2
 *
 * Input: operand1, operand2
 *
 * Output: outputBuf
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must defined by ARITHMETIC_BINARY_BUFF_LEN.
 */
void multiplication(const unsigned char *operand1, const unsigned char *operand2, unsigned char *outputBuf)
{
	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char temp1[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char temp2[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	register size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	register unsigned short bitMask = 1;
	register int bitOffset = 0;

	while (!(byteInd == 0))
	{

		if (bitMask > 128)
		{ //force in line
			bitMask = 1;
			--byteInd;
		}
		if (operand2[byteInd] & bitMask)
		{
			memcpy(temp1, operand1, ARITHMETIC_BINARY_BUFF_LEN);
			register size_t i;
			for (i ^= i; i < bitOffset; ++i)
			{
				shiftLeft(temp1);
			}
			addition(outputBuf, temp1, temp2);
			memcpy(outputBuf, temp2, ARITHMETIC_BINARY_BUFF_LEN);
		}
		++bitOffset;
		bitMask <<= 1;
	}
}

/*
 * Computes the division of operand1 by operand2
 *
 * Input: operand1, operand2
 *
 * Output: outputBuf
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must defined by ARITHMETIC_BINARY_BUFF_LEN.
 */
void division(const unsigned char *operand1, const unsigned char *operand2, unsigned char *outputBuf)
{
	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char operand1Temp[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	memcpy(operand1Temp, operand1, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char temp[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char resultTemp[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	register size_t byteInd = 0;
	register unsigned short bitInd = 0;
	register unsigned short bitMask = 128;

	register size_t shiftAmount = 0;

	// Perform division
	while (byteInd < ARITHMETIC_BINARY_BUFF_LEN)
	{
		while (bitMask > 0)
		{

			memcpy(temp, operand1Temp, ARITHMETIC_BINARY_BUFF_LEN);
			shiftAmount = 8 * ARITHMETIC_BINARY_BUFF_LEN - 8 * byteInd - bitInd - 1;
			register size_t i;
			for (i ^= i; i < shiftAmount; ++i)
			{
				shiftRight(temp);
			}

			if (lessThanEqual(operand2, temp) >= 0)
			{
				break;
			}
			bitMask >>= 1;
			++bitInd;

		} //end of while bitMask > 0

		if (lessThanEqual(operand2, temp) >= 0)
		{
			outputBuf[byteInd] |= (bitMask);

			memcpy(temp, operand2, ARITHMETIC_BINARY_BUFF_LEN);
			register size_t i;
			for (i ^= i; i < shiftAmount; ++i)
			{
				shiftLeft(temp);
			}

			subtraction(operand1Temp, temp, resultTemp);
			memcpy(operand1Temp, resultTemp, ARITHMETIC_BINARY_BUFF_LEN);
		}

		if (bitMask == 0)
		{
			++byteInd;
			bitMask = 128;
			bitInd = 0;
		}
	} //end of while byteInd < ARITHMETIC_BINARY_BUFF_LEN
} //end of funct

/*
 * Computes the decimal equivalent of the value stored within the buffer
 *
 * Input: val
 *
 * Note: Behavior is undefined if val is greater than SIZE_MAX
 */
uint32_t binaryToDecimal(const unsigned char *val)
{

	unsigned char temp[ARITHMETIC_BINARY_BUFF_LEN] __attribute__((aligned(4))) = {0};
	memcpy(temp, val, ARITHMETIC_BINARY_BUFF_LEN);

	register size_t byteInd = 0;
	unsigned char c;

	while (byteInd <= (ARITHMETIC_BINARY_BUFF_LEN + (ARITHMETIC_BINARY_BUFF_LEN % ARITHMETIC_BINARY_STORE_LEN)) / 2)
	{
		temp[ARITHMETIC_BINARY_BUFF_LEN - (byteInd + 1)] = val[byteInd];
		temp[byteInd] = val[ARITHMETIC_BINARY_BUFF_LEN - (byteInd + 1)];
		++byteInd;
	}
	return *(uint32_t *)(temp);
}
