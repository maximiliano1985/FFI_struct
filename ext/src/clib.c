/*************************************************************
* 
* Program:      FFI_struct
* 
* File:         clib.c
* 
* Description:  Simple examples of FFI library implementation
* 
* Author:       Carlos Maximiliano Giorgio Bort (cmgb)
* 
* Environment:  gcc version 4.2.1 (Based on Apple Inc. build 5658)
*               (LLVM build 2336.1.00)
*
*               i686-apple-darwin10
*              
* Notes:        Copyright (c) 2012 University of Trento.
*               All rights reserved.
* 
*               To generate the shared object with cgg:
*               gcc -c clib.c ; gcc -shared -o clib.so clib.o
* 
* Revisions:    1.00  02/08/12 (cmgb) First release
* 
*************************************************************/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define SIZE_OF_ARRAY 10

typedef unsigned int uint8;

time_t StartT;

// Structure whose element is a string that will be written and read in Ruby
// @author cmgb
struct
{
  uint8 String[SIZE_OF_ARRAY];
} MyArray_t;


// Structure whose values are defined in Ruby and read in C 
// @author cmgb
typedef struct _OUT
{
  float par1, par2;
} OUT, *pOUT;

// Structure whose values are defined in C and read in Ruby 
// @author cmgb
typedef struct _IN
{
  float out1, out2;
} IN, *pIN;

// Reads the parameters of the OUT structure passed with a pointer
// @param [Pointer] stc pointer to a OUT type structure
// @author cmgb
void structure_to_C(pOUT stc)
{
  StartT = time(NULL);
  printf("The struct has par1: %f, and par2 %f\n", stc->par1, stc->par2);
}

// Returns the elapsed time since the program started
// @return [Uint] the elapsed time
// @author cmgb
unsigned int elapsed_time()
{
  sleep(1);
  time_t EndT = time(NULL);
  return EndT - StartT;
}

// Writes the parameters of the IN structure passed with a pointer
// @param [Pointer] stc pointer to a IN type structure
// @author cmgb
pIN structure_to_Ruby(pIN stc){
  stc -> out1 = 1.1;
  stc -> out2 = 2.2;
  return stc;
}

// Reads the parameters of the IN structure passed with a pointer
// @param [Pointer] stc pointer to a IN type structure
// @author cmgb
void put_structure_to_Ruby(pIN stc)
{
  printf("The struct has out1: %f, and out2 %f\n", stc->out1, stc->out2);
}
