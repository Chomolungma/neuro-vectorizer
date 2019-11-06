#include "header.h"

short sa[2048];
short sb[2048];
int   out1[2048] ALIGNED16;
int   out2[2048] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, short *__restrict__ sb, int* __restrict__ out1, int* __restrict__ out2) {
  int i;
  for (i = 0; i < 2048-1; i+=2) {
    out1[i] = (int) sa[i];
out1[i+1] = (int) sa[i+1];
    out2[i] = (int) sb[i];
out2[i+1] = (int) sb[i+1];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[2048]);
  init_memory(&out2[0], &out2[2048]);
  init_memory(&sa[0], &sa[2048]);
  init_memory(&sb[0], &sb[2048]);
  BENCH("Example10b", example10b(sa,sb,out1,out2), Mi*4/2048*512, digest_memory(&out1[0], &out1[2048])+digest_memory(&out2[0], &out2[2048]));
 
  return 0;
}