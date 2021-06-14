
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

//E is public exponent
//M modulation value (PQ)
//X 
//Z = X ^ E mod M

uint32_t decryt;
uint32_t encryt;

uint32_t rsa_mod_exp(uint32_t X, uint32_t E, uint32_t M)
{
   
    uint32_t Z0 = 1; 
    uint32_t P0 = X;
    uint32_t Z1 = 1;
    uint32_t P1 = 0;

//Modular exponentiation alorgithm
    for (uint32_t i = 1; i != 0; i <<= 1) //FOR i = 0 to n-1 Loop, shifting i each loop
    {
        uint32_t e = E & i; //AND E and i
        P1 = (P0 * P0) % M; //Pi+1 = Pi^2 mod M
        if (e) //if true
        {
            Z1 = (Z0 * P0) % M; 
        }
        else
        {
            Z1 = Z0;
        }
        //increment
        P0 = P1;
        Z0 = Z1;

	
    }
    //print the final value
    //printf("Value = %u\n", Z1);
    return Z1;
}

int main() {
    decryt = rsa_mod_exp(855,2753,3233); //should print 123 (decryt)
    encryt = rsa_mod_exp(123,17,3233); //should print 855(encryt)

    printf("Decrypted Value = %u\n", decryt);
    printf("Encrypted Value = %u\n", encryt);

return 0;

}