#include "GH_Modular_Exponentiation.h"
#include <assert.h>

#define charBufferLen 200

typedef struct {
	char e[charBufferLen];
	char d[charBufferLen];
	char plainText[charBufferLen];
	char cipherText[charBufferLen];
} test;

int main(void) {
	/*
	 16 bit
	 Prerequisite:
	 	Set ARITHMETIC_BINARY_BUFF_LEN to 5
	 */
	char mod[] = "59989";
	test testArr[] = {{"4861", "15741", "500", "59196"}};

	/*
	 128 bit
	 Prerequisite:
	 	Set ARITHMETIC_BINARY_BUFF_LEN to 33
	 p =15059197368646682309
	 q = 8031401003146336133
	  */
	/*
	char mod[] = "120946452853127629758136486859378571097";
	test testArr[] = {{"65537",
					"35076815072087475141889576918130805489",
					"500",
					"93636552947963594924961218555049180126"}};
	*/
	

	/*
	 512 bit
	 Prerequisite:
	 	Set ARITHMETIC_BINARY_BUFF_LEN to 129
	 p = 74010976080769448882849484969906317231425676519069851217175402226218157764419
	 q = 106068144207230189795842921255910978631884042719754290716530807673870132832657
	 */
	/*
	char mod[] = "7850206883852918155100161868653507996296677763962914561176771657590119587184597952087103214601153411344056181627564936414571818776804681114989022955831283";
	test testArr[] = {{"65537", 
	 				"7496847555422167456143153193973131284071900929446677962683226387133875743520624401717717684038884984576071364457149544684389064730040583279442164790774881", 
	 				"500",
	 				"6188085185875815690197915004566544069227156450568490907170840700917848556682562977791856329295129315199407038715305911247075399830064416495554161262986964"}};
	*/

	for(int i = 0; i < sizeof(testArr)/sizeof(testArr[0]); ++i) {
		printf("INSIDE\n");
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
	}

	printf("ALL TESTS PASSED\n");
}
