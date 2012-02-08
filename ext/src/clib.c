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
*               To compile the shared object with cgg:
*               gcc -c clib.c ; gcc -shared -o clib.so clib.o
* 
* Revisions:    1.00  02/08/12 (cmgb) First release
* 
*************************************************************/

#include "clib.h"

time_t StartT;

// Reads the parameters of the OUT structure passed with a pointer
// @param [Pointer] stc pointer to a OUT type structure
// @author cmgb
void structure_to_C(pOUT stc)
{
  StartT = time(NULL);
  printf("The struct has par1: %.2f, and par2 %.2f\n", stc->par1, stc->par2);
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
  printf("The struct has out1: %.2f, and out2 %.2f\n", stc->out1, stc->out2);
}
