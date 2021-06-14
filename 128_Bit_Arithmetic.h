#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ARITHMETIC_STRING_BUFF_LEN 200
#define ARITHMETIC_BINARY_BUFF_LEN 16

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
bool stringToBits(const char *inputBuf, char *stringOutputBuf, unsigned char *binaryOutputBuf) {
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



