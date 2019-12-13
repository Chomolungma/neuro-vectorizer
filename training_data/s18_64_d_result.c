#include "header.h"
unsigned short usa[64];
unsigned int   ua[64];

__attribute__((noinline))
void example23 (unsigned short *d, unsigned int *result)
{
  int i;

  for (i = 0; i < 64; i++)
    *result++ = *d++ << 7;
}

int main(int argc,char* argv[]){
  init_memory(&ua[0], &ua[64]);
      BENCH("Example23",  example23(usa,ua), Mi*8/64*512, digest_memory(&usa[0], &usa[64]));
  return 0;
}