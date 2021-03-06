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

## Command Line Commands 
- Run Time of Execution: time ./TestLookupTableEncryptDecrypt.exe
     - Real: time from start to finish of the call
     - User: amount of CPU time spent in user mode
     - Sys: amount of CPU time spent in the kernel within the process   
- Generate Assembly Code: arm-linux-gcc -S TestLookupTableEncryptDecrypt.c -std=c99
- Compiling C Code: arm-linux-gcc -static -o TestLookupTableEncryptDecrypt.exe TestLookupTableEncryptDecrypt.c -std=c99
- Compiling C Assembly: arm-linux-gcc -o TestLookupTableEncryptDecrypt.exe TestLookupTableEncryptDecrypt.s -std=c99
- Profiling: arm-linux-gcc -pg TestLookupTableEncryptDecrypt.c (upload to arm Machine), ./a.out, (bring gmon.out back to local machine), gprof
- O3 Flag:
    - Generate Assembly Code: arm-linux-gcc -S -O3 TestLookupTableEncryptDecrypt.c -std=c99
    - Compiling C Code: arm-linux-gcc -o TestLookupTableEncryptDecrypt.exe TestLookupTableEncryptDecrypt.c -O3 -std=c99
    - Compiling Assembly Code: arm-linux-gcc -o TestLookupTableEncryptDecrypt.exe TestLookupTableEncryptDecrypt.s -O3 -std=c99





