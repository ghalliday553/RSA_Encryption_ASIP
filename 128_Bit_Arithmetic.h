#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ARITHMETIC_STRING_BUFF_LEN 200
#define ARITHMETIC_BINARY_BUFF_LEN 32
#define ARITHMETIC_BINARY_STORE_LEN ARITHMETIC_BINARY_BUFF_LEN/2

void printArr(const unsigned char* ptr) {
	for (int i = 0; i<ARITHMETIC_BINARY_BUFF_LEN; i++) {
		printf("%02x", ptr[i]);
	}
	printf("\n");
}

/*
 * Helper function for stringToBits()
 */
void divStringByTwo(char *buf) {
	int add = 0;
	for (char *it = buf; *it != '\0'; ++it) {
		int digit = *it - '0';
		digit /= 2;
		digit += add;
		switch(*it) {
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
	for(char *it = buf; *it == '0'; ++it) {
		++zeroOffset;
	}
	memmove(buf, buf+zeroOffset, strlen(buf)-zeroOffset+1);
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
bool stringToBinary(const char *inputBuf, unsigned char *outputBuf) {
	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	char stringTempBuf[ARITHMETIC_STRING_BUFF_LEN] = {0};

	size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	unsigned int bitMask = 1;

	strcpy(stringTempBuf, inputBuf);

	while(strlen(stringTempBuf)) {
		switch(stringTempBuf[strlen(stringTempBuf)-1]) {
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

		if (bitMask > 128) {
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
bool addBinaries(const unsigned char *operand1, const unsigned char *operand2, unsigned char *outputBuf) {

	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	bool carry = false;
	unsigned int binaryBitMask = 1;

	while (1) {
		while (binaryBitMask <= 128) {
			if ((binaryBitMask & operand1[byteInd]) >= 1 && (binaryBitMask & operand2[byteInd]) >= 1) {
				if(carry) {
					outputBuf[byteInd] |= binaryBitMask;
				} 
				carry = true;
			} else if ((binaryBitMask & operand1[byteInd]) >= 1 || (binaryBitMask & operand2[byteInd]) >= 1) {
				if (carry) {
					carry = true;
				} else {
					outputBuf[byteInd] |= binaryBitMask;
					carry = false;
				}
			} else {
				if (carry) {
					outputBuf[byteInd] |= binaryBitMask;
				}
				carry = false;
			}

			binaryBitMask <<= 1;
		}
		binaryBitMask = 1;
		if (byteInd == 0) {
			break;
		} else {
			--byteInd;
		}
	}
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
bool subtractBinaries(const unsigned char *operand1, const unsigned char *operand2, unsigned char *outputBuf) {
	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	bool borrow = false;
	unsigned int binaryBitMask = 1;

	while (1) {
		while (binaryBitMask <= 128) {
			if ((binaryBitMask & operand1[byteInd]) >= 1 && (binaryBitMask & operand2[byteInd]) >= 1) {
				if(borrow) {
					outputBuf[byteInd] |= binaryBitMask;
				}
			} else if ((binaryBitMask & operand1[byteInd]) >= 1 && (binaryBitMask & operand2[byteInd]) == 0) {
				if (borrow) {
					borrow = false;
				} else {
					outputBuf[byteInd] |= binaryBitMask;
				}
			} else if ((binaryBitMask & operand1[byteInd]) == 0 && (binaryBitMask & operand2[byteInd]) >= 1) {
				if (!borrow) {
					outputBuf[byteInd] |= binaryBitMask;
				}
				borrow = true;
			} else {
				if (borrow) {
					outputBuf[byteInd] |= binaryBitMask;
				}
			}

			binaryBitMask <<= 1;
		}
		binaryBitMask = 1;
		if (byteInd == 0) {
			break;
		} else {
			--byteInd;
		}
	}
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
int lessThanEqual(const unsigned char *operand1, const unsigned char *operand2) {
	unsigned int bitMask = 128;
	size_t byteInd = 0;

	while(byteInd < ARITHMETIC_BINARY_BUFF_LEN) {
		while (bitMask >= 1) {
			if ((operand1[byteInd] & bitMask) && !(operand2[byteInd] & bitMask)) {
				return -1;
			} else if ((operand2[byteInd] & bitMask) && !(operand1[byteInd] & bitMask)) {
				return 1;
			}
			bitMask >>= 1;
		}

		bitMask = 128;
		++byteInd;
	}
	return 0;
}


/*
 * Shifts the binary number right by 1 in place
 *
 * Input/Output: operand1
 */
bool shiftRight(unsigned char *operand1) {
	size_t byteInd = 0;
	unsigned char newTemp = 0;
	unsigned char prevTemp = 0;

	while(byteInd < ARITHMETIC_BINARY_BUFF_LEN) {
		prevTemp = newTemp;
		newTemp = (operand1[byteInd] & 1);
		operand1[byteInd] >>= 1;
		operand1[byteInd] |= (prevTemp<<7);

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
size_t bitOffset(const unsigned char *operand1) {
	size_t byteInd = 0;
	unsigned int bitMask = 128;

	size_t bitOffset = 0;
	while(byteInd < ARITHMETIC_BINARY_BUFF_LEN) {
		if (operand1[byteInd] != 0x0) {
			while (bitMask >= 1) {
				if ((bitMask & operand1[byteInd]) != 0x0) {
					return bitOffset;
				}
				bitMask >>= 1;
				++bitOffset;
			}
			bitMask = 128;
		}
		bitOffset += 8;
		++byteInd;
	}

	return ARITHMETIC_BINARY_BUFF_LEN*8;
}


/*
 * Computes the montgomery multiplication of operand1 and operand2 with modulus mod
 *
 * Input: operand1, operand2, mod
 *
 * Output: outputBuf
 *	- Output buffer where the product is written to
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must defined by ARITHMETIC_BINARY_BUFF_LEN.
 */
bool montgomeryMultiplication(const unsigned char *operand1, const unsigned char *operand2, const unsigned char *mod, unsigned char *outputBuf) {

	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned char t[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char temp[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned int n = 0;

	size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN-1;
	unsigned short int bitMask = 1;

	size_t bitsToCount = ARITHMETIC_BINARY_BUFF_LEN*8 - bitOffset(mod);

	size_t totalBits = 0;
	bool abort = false;

	while(1) {
		while (bitMask <= 128) {
			if (totalBits == bitsToCount) {
				abort = true;
				break;
			}
			n = (t[ARITHMETIC_BINARY_BUFF_LEN-1] & 0x1)^((operand1[byteInd] & bitMask) && (operand2[ARITHMETIC_BINARY_BUFF_LEN-1] & 0x1));
			if (operand1[byteInd] & bitMask) {
				addBinaries(t, operand2, temp);
				memcpy(t, temp, ARITHMETIC_BINARY_BUFF_LEN);
			}
			if (n) {
				addBinaries(t, mod, temp);
				memcpy(t, temp, ARITHMETIC_BINARY_BUFF_LEN);
			}
			shiftRight(t);

			bitMask <<= 1;
			++totalBits;
		}

		bitMask = 1;
		if (byteInd == 0 || abort) {
			break;
		} else {
			--byteInd;
		}
	}

	while (lessThanEqual(t, mod) <= 0) {
		subtractBinaries(t, mod, temp);
		memcpy(t, temp, ARITHMETIC_BINARY_BUFF_LEN);
	}
	memcpy(outputBuf, t, ARITHMETIC_BINARY_BUFF_LEN);

	return true;
}

/*
 * Computes the modulus multiplication of operand1 and operand2 with modulus mod
 *
 * Input: operand1, operand2, mod
 *
 * Output: outputBuf
 *	- Output buffer where the product is written to
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must defined by ARITHMETIC_BINARY_BUFF_LEN.
 */
bool montgomeryMultiplicationHelper(const unsigned char *operand1, const unsigned char *operand2, const unsigned char *mod, unsigned char *outputBuf) {
	unsigned char r2[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char one[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char resultTemp1[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char resultTemp2[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	unsigned char resultTemp3[ARITHMETIC_BINARY_BUFF_LEN] = {0};

	size_t m = ARITHMETIC_BINARY_BUFF_LEN*8 - bitOffset(mod);
	size_t m2 = m*2;

	size_t byte = m2/8;
	size_t remainingBits = m2 - byte*8;
	unsigned short int bitMask = 1;
	for(size_t i = 0; i < remainingBits; ++i) {
		bitMask<<=1;
	}
	r2[ARITHMETIC_BINARY_BUFF_LEN-1-byte] |= bitMask;

	montgomeryMultiplication(operand1, r2, mod, resultTemp1);
	montgomeryMultiplication(operand2, r2, mod, resultTemp2);
	montgomeryMultiplication(resultTemp1, resultTemp2, mod, resultTemp3);
	stringToBinary("1", one);
	montgomeryMultiplication(one, resultTemp3, mod, outputBuf);

	return true;
}

/*
 * Computes the decimal equivalent of the value stored within the buffer
 *
 * Input: val
 *
 * Note: Behavior is undefined if val is greater than SIZE_MAX
 */
size_t binaryToDecimal(const unsigned char *val) {
	unsigned char temp[ARITHMETIC_BINARY_BUFF_LEN] = {0};
	memcpy(temp, val, ARITHMETIC_BINARY_BUFF_LEN);

	size_t offset = sizeof(size_t);
	size_t byteInd = 0;
	unsigned char c;
	while((byteInd+offset) < ARITHMETIC_BINARY_BUFF_LEN - offset/2) {
		c = temp[ARITHMETIC_BINARY_BUFF_LEN - (byteInd+1)];
		temp[ARITHMETIC_BINARY_BUFF_LEN - (byteInd+1)] = temp[offset + byteInd];
		temp[offset + byteInd] = c;
		++byteInd;
	}
	return *(size_t*)(temp+offset);
}



