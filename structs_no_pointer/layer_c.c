#include <stdio.h>
/*
To create the shared object
http://stackoverflow.com/questions/5280175/how-to-use-ruby-ffi-for-calling-custom-c-code-in-a-ruby-gem
*/

typedef struct _WHAT {
  unsigned int address;
  float override;
  //void * something;
} WHAT;

int scan_struct(WHAT w) {
  printf("address: %5.u, override %2.2f\n", w.address, w.override);
  return(0) ; //w.address, w.override;
}