//Table of Powers RSA encryption 
//June 10th 2021

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define P (61)
#define Q (53)
#define PrivateExponent (2753)
#define PublicExponent (17)

uint64_t ArrayOfPowers [128]; //need to be able to handle 128 bit integers, cant right now
uint64_t Modulus = (P*Q); //PQ = 3233, might want to change to a define, P*Q was not working

//function declarations
void TableOfValueCompute(uint64_t Array[],uint64_t Mod, int32_t Value);
int16_t DecryptionAlgorithm(uint32_t Exponent, uint32_t Mod);


//Computes table of Values and stores into an array
void TableOfValueCompute(uint64_t Array[], uint64_t Mod, int32_t Value){
    //value should be: 855
    Array[0] = Value;
    Array[1] = (Value*Value) % Mod; //should equal 367
    int i;
    for(i = 2; i <128; i++){
        Array[i] = (Array[i-1]*Array[i-1]) % Mod;
        printf("Array[i] = %u\t", Array[i]);
        printf("i = %u\n", i);
    }
}//end of Table Of Value Compute


//decrypts or encrypts depending on values passed in
int16_t DecryptionAlgorithm(uint32_t Exponent, uint32_t Mod){
//gobal Arrays
    uint64_t decrytpedValue = 1;//decrytpedValue needs to be initalized to 1
    int count = 0;
    uint32_t i; 

    for(i = 1; i < Exponent; i <<= 1){
        uint32_t e = (Exponent & i);//will return the values for exponents

        if(e){ //if the exponent has 1 in the place begin mods
            decrytpedValue *= ArrayOfPowers[count]; 
            decrytpedValue = decrytpedValue % Mod;
            // printf("decrytpedValue = %u\t", decrytpedValue);
            // printf("count = %u\t", count);
            // printf("i = %u\n", i);
        }
        count++;//used as index for array
    }//end of for loop 
    return decrytpedValue;
}//end of decrytped algorthium


int main() {
   
    int16_t DecryptedMessage = 0;

    TableOfValueCompute(ArrayOfPowers, Modulus, 855); //855 is the message to decrypt
    DecryptedMessage = DecryptionAlgorithm(PrivateExponent, Modulus);
    printf("Decrypted Value = %u\n", DecryptedMessage); //should print 123

    //Encryption Check
    // TableOfValueCompute(PowerOfValueArray, Modulus, 123); //855 is the message to decrypt
    // DecryptedMessage = DecryptionAlgorithm(PublicExponent, Modulus);
    // printf("Encrypted Value = %u\n", DecryptedMessage); //should print 123

return 0;

}
