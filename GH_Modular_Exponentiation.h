#include "128_Bit_Arithmetic.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void mod_encrypt_decrypt(const unsigned char *num, const unsigned char *exp, const unsigned char *mod, unsigned char* out) {
    memset(out, 0, ARITHMETIC_BINARY_BUFF_LEN);

    unsigned char z0[ARITHMETIC_BINARY_BUFF_LEN] = {0};
    z0[ARITHMETIC_BINARY_BUFF_LEN-1] |= 1;

    unsigned char z1[ARITHMETIC_BINARY_BUFF_LEN] = {0};
    z1[ARITHMETIC_BINARY_BUFF_LEN-1] |= 1;

    unsigned char p0[ARITHMETIC_BINARY_BUFF_LEN] = {0};
    memcpy(p0, num, ARITHMETIC_BINARY_BUFF_LEN);

    unsigned char p1[ARITHMETIC_BINARY_BUFF_LEN] = {0};

    size_t expBits = ARITHMETIC_BINARY_BUFF_LEN*8 - bitOffset(exp);

    size_t byteInd = ARITHMETIC_BINARY_BUFF_LEN - 1;

    unsigned short bitMask = 1;
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

            montgomeryMultiplicationHelper(p0, p0, mod, p1);

            if (exp[byteInd] & bitMask) {
                montgomeryMultiplicationHelper(z0, p0, mod, z1);
            } else {
                memcpy(z1, z0, ARITHMETIC_BINARY_BUFF_LEN);
            }

            memcpy(p0, p1, ARITHMETIC_BINARY_BUFF_LEN);
            memcpy(z0, z1, ARITHMETIC_BINARY_BUFF_LEN);


            bitMask <<= 1;
            ++bitCounter;

            printf("bitCounter is %lu\n", bitCounter);
        }

        bitMask = 1;
        if(byteInd == 0 || bitCounter == expBits) {
            break;
        } else {
            --byteInd;
        }
    }

    memcpy(out, z1, ARITHMETIC_BINARY_BUFF_LEN);
}