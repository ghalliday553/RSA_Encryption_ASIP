# RSA_Encryption_ASIP

## Lookup Table Generation

Update the "mod" buffer with the desired modulus value
Program output will produce a "LookupTable.bin" file

Notes:
- ARITHMETIC_STRING_BUFF_LEN may need to be increased
- ARITHMETIC_BINARY_BUFF_LEN may need to be increased (size requirements can be found within APIntegeryLibrary.h)

## Testing Lookup Table Encryption/Decryption

All test cases within the "testArr" array will be evaluated
Add or remove test cases as needed

Notes:
- "mod" within "TestLookupTableEncryptDecrypt.c" must match the modulus value used to generate the lookup table
- "LookupTable.bin" must be located in the same directory

## Testing Modular Exponentiation Encryption/Decryption

16, 128, and 512 bit RSA keys have been provided and should be commented out as necessary.

Notes:
- ARITHMETIC_STRING_BUFF_LEN may need to be increased
- ARITHMETIC_BINARY_BUFF_LEN may need to be increased (size requirements can be found within APIntegeryLibrary.h)





