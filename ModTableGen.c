//Table of Powers RSA encryption 

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "128_Bit_Arithmetic.h"
#include <string.h>

#define P (61)
#define Q (53)
#define PrivateExponent (2753)
#define PublicExponent (17)

//uint64_t ArrayOfPowers [128]; //need to be able to handle 128 bit integers, cant right now
uint64_t Modulus = (P*Q); //PQ = 3233, might want to change to a define, P*Q was not working
unsigned char ArrayOfPowers[ARITHMETIC_BINARY_BUFF_LEN] = {0};


//function declarations
void TableOfValueCompute(char *Mod, char *Value);
int16_t DecryptionAlgorithm(uint32_t Exponent, uint32_t Mod);


//Computes table of Values and stores into an array
void TableOfValueCompute(char *Mod, char *Value){
    //value should be: 855
    //printf("Starting Computing Powers\n");
    FILE *fptr;
    fptr = fopen("TableOfPowers.txt", "a");// opening file in writing mode
    
    //formating data
    fprintf(fptr,"2^i\t");
    fprintf(fptr,"Mod of %s\n", Value);

    unsigned char out[200][ARITHMETIC_BINARY_BUFF_LEN] = {'\0'}; //array of strinf initalized
    char stringBuf[ARITHMETIC_STRING_BUFF_LEN] = {'\0'};
	unsigned char binaryBuf1[ARITHMETIC_BINARY_BUFF_LEN] = {'\0'};
	unsigned char binaryBuf2[ARITHMETIC_BINARY_BUFF_LEN] = {'\0'};

    //need to pre compute value to be saved 
	stringToBinary(Value, stringBuf, binaryBuf1);
	stringToBinary(Mod, stringBuf, binaryBuf2);
	montgomeryMultiplicationHelper(binaryBuf1, binaryBuf1, binaryBuf2, out[0]);	
	//printf("out[0] = ");
    //printArr(out[0]); //prints 16f
    fprintf(fptr,"%u\t", 0);
    WriteToFile(out[0],fptr);
    fputs("\n",fptr);

    //computes second value
	montgomeryMultiplicationHelper(out[0], out[0], binaryBuf3, out[1]);	
    //printf("out[1] = ");
    //printArr(out[1]);
    fprintf(fptr,"%u\t", 1);
    WriteToFile(out[1],fptr);
    fputs("\n",fptr);

    //computes 3rd value
    montgomeryMultiplicationHelper(out[1], out[1], binaryBuf3, out[2]);	
    //printf("out[1] = ");
    //printArr(out[2]);
    fprintf(fptr,"%u\t", 2);
    WriteToFile(out[2],fptr);
    fputs("\n",fptr);

    int i = 0;
    
    for(i = 3; i <128; i++){

        montgomeryMultiplicationHelper(out[i-1], out[i-1], binaryBuf3, out[i]);
        //printf("i = %u\t", i);
        //printf("out[i] = ");
        //printArr(out[i]);

        //comparing to first value
        if(CompareString(out[0], out[i]) == 0 ){
            //printf("strcmp(out[0], out[i]) -> Same Value for i = %u\n", i);
            fprintf(fptr,"%u\t", i);
            WriteToFile(out[i],fptr);
            fputs("\n",fptr);
            break; //breaks when the strings are the same
        }//end of if 

        //if it repeats at 3 in
        else if(CompareString(out[2], out[i]) == 0){
            fprintf(fptr,"%u\t", i);
            WriteToFile(out[i],fptr);
            fputs("\n",fptr);
            break;
        } 
        
        fprintf(fptr,"%u\t", i);
        WriteToFile(out[i],fptr);
        fputs("\n",fptr);
    }//end of for loop
    fputs("\n",fptr);
    
    fclose(fptr); //closes file
}//end of Table Of Value Compute



int main() {

    int x = 800;
    char y[100];

    int16_t DecryptedMessage = 0;

    //change 100 to get more values...
    for(int i = 0; i < 100; i++){
        sprintf(y, "%u",x);
        TableOfValueCompute("3233",y);
        x++;
    }
    
    // TableOfValueCompute("3233","856");
    // TableOfValueCompute("3233","857");
    // TableOfValueCompute("3233","858");
    // TableOfValueCompute("3233","859");

return 0;

}

return 0;

}
