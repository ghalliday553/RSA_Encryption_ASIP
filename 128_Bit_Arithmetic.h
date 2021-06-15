#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ARITHMETIC_STRING_BUFF_LEN 200
#define ARITHMETIC_BINARY_BUFF_LEN 32

void printArr(unsigned char* ptr) {
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
bool stringToBinary(const char *inputBuf, char *stringOutputBuf, unsigned char *binaryOutputBuf) {
	char stringTempBuf[ARITHMETIC_STRING_BUFF_LEN] = {0};
	char stringOutputStack[ARITHMETIC_STRING_BUFF_LEN] = {0};
	int counter = 0;
	int len;

	// Convert decimal string to binary string
	strcpy(stringTempBuf, inputBuf);

	while(strlen(stringTempBuf)) {
		switch(stringTempBuf[strlen(stringTempBuf)-1]) {
			case '1':
			case '3':
			case '5':
			case '7':
			case '9':
				stringOutputStack[counter] = '1';
				break;
			default:
				stringOutputStack[counter] = '0';
				break;
		}
		divStringByTwo(stringTempBuf);
		counter++;
	}
	
	len = --counter;
	while(counter >= 0) {
		stringOutputBuf[len-counter] = stringOutputStack[counter];
		--counter;
	}
	stringOutputBuf[len+1] = '\0';

	// Convert binary string to binary
	memset(binaryOutputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	unsigned int binaryBitMask = 1;
	char *it = stringOutputBuf;
	unsigned char currentByte = 0x00;
	unsigned int byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;

	counter = len;
	while (counter >= 0) {
		if (binaryBitMask <= 128) {
			if (stringOutputBuf[counter] == '1') {
				currentByte |= binaryBitMask;
			}
			binaryBitMask <<= 1;
			--counter;
		} else {
			binaryBitMask = 1;
			binaryOutputBuf[byteInd] = currentByte;
			--byteInd;
			currentByte = 0x00;
		}
	}

	if (binaryBitMask > 1) {
		binaryOutputBuf[byteInd] = currentByte;
	}

	return true;
}

/*
 * Computes the sum of two binary numbers represented by strings
 *
 * Input: operand1, operand2
 *	- Input strings representing binary numbers.
 * 	- operand1 and operand2 do not need to be the same length.
 *
 * Output: outputBuf
 *	- Output buffer where the sum string is written to
 *
 * Note: outputBuf must be large enough to hold the largest needed sum. This size must be defined by ARITHMETIC_STRING_BUFF_LEN.
 */
bool addBinaryStrings(const char *operand1, const char *operand2, char *outputBuf) {
	char tempOperand1[ARITHMETIC_STRING_BUFF_LEN] = {0};
	char tempOperand2[ARITHMETIC_STRING_BUFF_LEN] = {0};

	// Pad with zeros
	if (strlen(operand1) != strlen(operand2)) {
		int zeroPadCount;
		if (strlen(operand1) > strlen(operand2)) {
			zeroPadCount = strlen(operand1) - strlen(operand2);
			//printf("zero pad count is %i\n", zeroPadCount);
			memset(tempOperand2, '0', zeroPadCount);
			strcat(tempOperand2, operand2);
			strcpy(tempOperand1, operand1);
		} else {
			zeroPadCount = strlen(operand2) - strlen(operand1);
			memset(tempOperand1, '0', zeroPadCount);
			strcat(tempOperand1, operand1);
			strcpy(tempOperand2, operand2);
		}
	} else {
		strcpy(tempOperand1, operand1);
		strcpy(tempOperand2, operand2);
	}

	int inputOffset = strlen(tempOperand1)-1;
	int outputOffset = inputOffset+1;
	bool carry = false;

	while (inputOffset >= 0) {
		if (tempOperand1[inputOffset] == '1' && tempOperand2[inputOffset] == '1') {
			if(carry) {
				outputBuf[outputOffset] = '1';
			} else {
				outputBuf[outputOffset] = '0';
			}
			carry = true;
		} else if (tempOperand1[inputOffset] == '1' || tempOperand2[inputOffset] == '1') {
			if (carry) {
				outputBuf[outputOffset] = '0';
				carry = true;
			} else {
				outputBuf[outputOffset] = '1';
				carry = false;
			}
		} else {
			if(carry){
				outputBuf[outputOffset] = '1';
			} else {
				outputBuf[outputOffset] = '0';
			}
			carry = false;
		}

		--outputOffset;
		--inputOffset;
	}

	if (carry) {
		outputBuf[outputOffset] = '1';
		outputBuf[strlen(tempOperand1)+1] = '\0';
	} else {
		memmove(outputBuf, outputBuf+1, strlen(tempOperand1));
		outputBuf[strlen(tempOperand1)] = '\0';
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

	int byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	bool carry = false;
	unsigned int binaryBitMask = 1;

	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	while (byteInd >= 0) {
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
		--byteInd;
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
	int byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;
	bool borrow = false;
	unsigned int binaryBitMask = 1;

	memset(outputBuf, 0, ARITHMETIC_BINARY_BUFF_LEN);

	while (byteInd >= 0) {
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
		--byteInd;
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
 * 	- 0 if operand1 = operand2
 */
int lessThanEqual(const unsigned char *operand1, const unsigned char *operand2) {
	unsigned int bitMask = 128;
	int byteInd = 0;

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
	int byteInd = 0;
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
int bitOffset(const unsigned char *operand1) {
	int byteInd = 0;
	unsigned int bitMask = 128;

	int modBitOffset;
	while(byteInd < ARITHMETIC_BINARY_BUFF_LEN) {
		if (operand1[byteInd] != 0) {
			while (bitMask >= 1) {
				if ((bitMask & operand1[byteInd]) != 0) {
					return modBitOffset;
				}
				bitMask >>= 1;
				++modBitOffset;
			}
			bitMask = 128;
		}
		modBitOffset += 8;
		++byteInd;
	}

	return ARITHMETIC_BINARY_BUFF_LEN -1;
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

	unsigned char t[ARITHMETIC_BINARY_BUFF_LEN];
	unsigned char temp[ARITHMETIC_BINARY_BUFF_LEN];
	unsigned char n = 0;

	int byteInd = ARITHMETIC_BINARY_BUFF_LEN-1;
	unsigned int bitMask = 1;

	int bitsToCount = ARITHMETIC_BINARY_BUFF_LEN*8 - bitOffset(mod);
	int totalBits = 0;
	bool abort = false;

	while(byteInd >= 0) {
		while (bitMask <= 128) {
			if (totalBits == bitsToCount) {
				abort = true;
				break;
			}
			n = (t[ARITHMETIC_BINARY_BUFF_LEN-1] & 1)^((operand1[byteInd] & bitMask) & (operand2[ARITHMETIC_BINARY_BUFF_LEN-1] & 1));
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

		if (abort) {
			break;
		}

		bitMask = 1;
		--byteInd;
	}

	if (lessThanEqual(t, mod) < 0) {
		subtractBinaries(t, mod, temp);
		memcpy(t, temp, ARITHMETIC_BINARY_BUFF_LEN);
	}
	memcpy(outputBuf, t, ARITHMETIC_BINARY_BUFF_LEN);

	return true;
}



