#include "header.h"

short sa[1024];
short sb[1024];
short sc[1024];
int   result1[1024] ALIGNED16;
int   result2[1024] ALIGNED16;
int   result3[1024] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, short *__restrict__ sb, short *__restrict__ sc, int* __restrict__ result1, int* __restrict__ result2, int* __restrict__ result3) {
  int i;
  for (i = 0; i < 1024; i++) {
    result1[i] = (int) sa[i];
    result2[i] = (int) sb[i];
    result3[i] = (int) sc[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result1[0], &result1[1024]);
  init_memory(&result2[0], &result2[1024]);
  init_memory(&result3[0], &result3[1024]);
  init_memory(&sa[0], &sa[1024]);
  init_memory(&sb[0], &sb[1024]);
  init_memory(&sc[0], &sc[1024]);
  BENCH("Example10b", example10b(sa,sb,sc,result1,result2,result3), Mi*4/1024*512, digest_memory(&result1[0], &result1[1024])+digest_memory(&result2[0], &result2[1024])+digest_memory(&result3[0], &result3[1024]));
 
  return 0;
}