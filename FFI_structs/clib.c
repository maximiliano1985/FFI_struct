// clear; gcc -c clib.c ; gcc -shared -o clib.so clib.o; ruby main.rb

#include <stdio.h>
#include <time.h>
#include <unistd.h>

time_t StartT;

typedef struct _OUT{
  float par1, par2;
} OUT;

typedef struct _IN{
  float ou1, out2;
  } IN, *pIN;
  
void structure_to_C(OUT *str){
  StartT = time(NULL);
  printf("The struct has par1: %f, and par2 %f\n", str->par1, str->par2);
}

unsigned int elapsed_time(){
  sleep(1);
  time_t EndT = time(NULL);
  return EndT - StartT;
}

pIN structure_to_Ruby(){
  IN *pin
  pin -> out1 = 1.1;
  pin -> out2 = 2.2;
  return po;
}