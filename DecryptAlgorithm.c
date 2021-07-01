
#include "128_Bit_Arithmetic.h"
#include <string.h>

#define P (61)
#define Q (53)
#define PrivateExponent (2753)
#define PublicExponent (17)

//uint64_t ArrayOfPowers [128]; //need to be able to handle 128 bit integers, cant right now
uint64_t Modulus = (P*Q); //PQ = 3233, might want to change to a define, P*Q was not working
//unsigned char Power[ARITHMETIC_BINARY_BUFF_LEN] = {0};
//unsigned char ArrayOfPowers[ARITHMETIC_BINARY_BUFF_LEN] = {0};

void DecryptionAlgorithm(uint32_t Exponent, char *Mod, char *ValueToEncrypt);

void DecryptionAlgorithm(uint32_t Exponent, char *Mod, char *ValueToEncrypt){


    unsigned char decrytpedValue[ARITHMETIC_BINARY_BUFF_LEN] = {'1'}; //need to be set to one so it doesnt 0 anything
    unsigned char inputDataIndex[ARITHMETIC_BINARY_BUFF_LEN] = {'\0'};
    unsigned char inputDataMods[ARITHMETIC_BINARY_BUFF_LEN] = {'\0'};
    unsigned char inputDataFile[ARITHMETIC_BINARY_BUFF_LEN] = {'\0'};
    unsigned char Powers[200][ARITHMETIC_BINARY_BUFF_LEN] = {'\0'}; //array of strinf initalized
    int i = 0;
    int count = 0;

    FILE *fptr; //opem file to read
    fptr = fopen("TableOfPowers.txt", "r");


    //Reads All Mods for value that users wants to encrypt.
    //Stores the Mods in a an array of Strings
    while(fscanf(fptr, "%s", inputDataFile)!=EOF){ //read until end of file
        
        if(strcmp(inputDataFile, "855") == 0){
            printf("Found for 855-----------------------> %s\n", inputDataFile);
         
            while((strcmp(inputDataIndex, "2^i") != 0) ){ //while next set of values
                fscanf(fptr, "%s %s", &inputDataIndex, &inputDataMods); //read file value 2 at a time
                strcpy(Powers[i],inputDataMods); //copy string into array of strings 
                //printf("\nPowers[%u]: %s \n",i, Powers[i]); 
                i++;
            }//end of while
            break;//break out of loop if value found 
        }//end of if
    }//end of while of file

    
    int j = 0;
    //To decrypt Value
    for(j = 1; j < Exponent; j <<= 1){
        uint32_t e = (Exponent & j);//will return the values for exponents

        if(e){ //if the exponent has 1 in the place begin mods

            //compute multipcation
            montgomeryMultiplicationHelper(decrytpedValue, Powers[count], Mod, decrytpedValue);	
        }
        count++;//used as index for array
    }//end of for loop 
    printArr(decrytpedValue);//print decrypted value
}//end of decrytped algorthium

int main(){

    DecryptionAlgorithm(17, "3233", "855");

    return 0;
}
