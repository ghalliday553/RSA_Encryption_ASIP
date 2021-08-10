#include "EncryptDecrypt.h"
#include <assert.h>

#define charBufferLen 25

typedef struct {
	char e[charBufferLen];
	char d[charBufferLen];
	char plainText[charBufferLen];
	char cipherText[charBufferLen];
} test;

int main(void) {
	char mod[] = "59989"; //P = 239, Q = 251
	
	test testArr[] = {
			{"4861", "15741", "500", "59196"}, //1
			{"691", "2411", "6789", "20190"}, //2
			{"43", "24907", "3457", "46052"}, //3
			{"11", "113591", "25482", "52220"}, //4
			{"151", "9851", "9785", "26100"}, //5
			{"859", "1039", "12634", "57198"}, //6
			{"1081", "1321", "9632", "49821"}, //7
			{"219", "7879", "12599", "15771"}, //8
			{"467", "2803", "56924", "31757"}, //9
			{"11", "54091", "894", "37159"} //10 
		};
	register int i;
	for(i ^= i; i < sizeof(testArr)/sizeof(testArr[0]); ++i) {
		unsigned char plainTextBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char cipherTextBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};

		unsigned char expBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char modBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};
		unsigned char outputBuf[ARITHMETIC_BINARY_BUFF_LEN] = {0};

		stringToBinary(testArr[i].plainText, plainTextBuf);
		stringToBinary(testArr[i].cipherText, cipherTextBuf);

		stringToBinary(testArr[i].e, expBuf);
		stringToBinary(mod, modBuf);

		encrypt_decrypt(plainTextBuf, expBuf, modBuf, outputBuf);
		printf("ENCRYPTED: ");
		printArr(outputBuf);

		assert(lessThanEqual(outputBuf, cipherTextBuf) == 0);

		stringToBinary(testArr[i].d, expBuf);

		encrypt_decrypt(cipherTextBuf, expBuf, modBuf, outputBuf);
		printf("DECRYPTED: ");
		printArr(outputBuf);
		assert(lessThanEqual(outputBuf, plainTextBuf) == 0);
	}

	printf("ALL TESTS PASSED\n");
}
