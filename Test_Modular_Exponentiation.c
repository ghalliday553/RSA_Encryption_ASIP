#include "GH_Modular_Exponentiation.h"
#include <assert.h>

#define charBufferLen 25

typedef struct {
	char e[charBufferLen];
	char d[charBufferLen];
	char plainText[charBufferLen];
	char cipherText[charBufferLen];
} test;

int main(void) {
	char mod[] = "16157591";
	
	test testArr[] = {{"7829", "1745117", "500", "5840670"}};

	for(int i = 0; i < sizeof(testArr)/sizeof(testArr[0]); ++i) {
		unsigned char plainTextBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char cipherTextBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};

		unsigned char expBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char modBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char outputBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};

		stringToBinary(testArr[i].plainText, plainTextBuf);
		stringToBinary(testArr[i].cipherText, cipherTextBuf);

		stringToBinary(testArr[i].e, expBuf);
		stringToBinary(mod, modBuf);

		mod_encrypt_decrypt(plainTextBuf, expBuf, modBuf, outputBuf);
		printf("ENCRYPTED: ");
		printArr(outputBuf);

		assert(lessThanEqual(outputBuf, cipherTextBuf) == 0);

		stringToBinary(testArr[i].d, expBuf);

		mod_encrypt_decrypt(cipherTextBuf, expBuf, modBuf, outputBuf);
		printf("DECRYPTED: ");
		printArr(outputBuf);
		assert(lessThanEqual(outputBuf, plainTextBuf) == 0);

		printf("inside\n");
	}

	printf("ALL TESTS PASSED\n");
}
