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

#include "cclib.h"

time_t StartT;


// Reads the parameters of the OUT structure passed with a pointer
// @param [Pointer] stc pointer to a OUT type structure
// @author cmgb
void structure_to_C(pOUT stc)
{
  StartT = time(NULL);
  init_obj(stc);
  //cout << "casa" << endl;
  //printf("The struct has par1: %.2f, and par2 %.2f\n", stc->par1, stc->par2);
}

void init_obj(pOUT stc){
  std::cout << "casa" << std::endl;
  bool ciccio;
  ciccio = 1;
  
  if (ciccio)
    std::cout << "occhei" <<std::endl;
    
  Conversione conv(stc);
  
  //for(int i = 0; i < 10; i++){
  //  std::cout << "sasa" <<std::endl;
  //  int mano;
  //}
}

Conversione::Conversione(OUT *stc)
{
  pstc = new OUT;
  
  pstc->par1 = stc->par1;
  pstc->par2 = stc->par2;
  
  cout << "The par1 is " << pstc->par1 <<", the par2 is " << pstc->par2 << endl;
}


Conversione::~Conversione( )
{
  delete pstc;
  std::cout << "Fine della conversionen"<<std::endl;
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
