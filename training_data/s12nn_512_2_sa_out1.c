#include "header.h"

short sa[512];
short sb[512];
short sc[512];
int   out1[512] ALIGNED16;
int   out2[512] ALIGNED16;
int   out3[512] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, short *__restrict__ sb, short *__restrict__ sc, int* __restrict__ out1, int* __restrict__ out2, int* __restrict__ out3) {
  int i;
  for (i = 0; i < 512; i+=2) {
    out1[i] = (int) sa[i];
    out2[i] = (int) sb[i];
    out3[i] = (int) sc[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[512]);
  init_memory(&out2[0], &out2[512]);
  init_memory(&out3[0], &out3[512]);
  init_memory(&sa[0], &sa[512]);
  init_memory(&sb[0], &sb[512]);
  init_memory(&sc[0], &sc[512]);
  BENCH("Example10b", example10b(sa,sb,sc,out1,out2,out3), Mi*4/512*512, digest_memory(&out1[0], &out1[512])+digest_memory(&out2[0], &out2[512])+digest_memory(&out3[0], &out3[512]));
 
  return 0;
}