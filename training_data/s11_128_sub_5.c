#include "header.h"

short sub2[128];
short s2[128];
short s3[128];
int   sub1[128] ALIGNED16;
int   i2[128] ALIGNED16;
int   i3[128] ALIGNED16;

__attribute__((noinline))
void example10a(short *__restrict__ sub2, short *__restrict__ s2, short *__restrict__ s3, int* __restrict__ sub1, int* __restrict__ i2, int* __restrict__ i3) {
  int i;
  for (i = 0; i < 128; i++) {
    sub1[i] = i2[i] + i3[i];
    sub2[i] = s2[i] + s3[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&sub1[0], &sub1[128]);
  init_memory(&i2[0], &i2[128]);
  init_memory(&i3[0], &i3[128]);
  init_memory(&sub2[0], &sub2[128]);
  init_memory(&s2[0], &s2[128]);
  init_memory(&s3[0], &s3[128]);
  BENCH("Example10a", example10a(sub2,s2,s3,sub1,i2,i3), Mi/128*512, digest_memory(&sub1[0], &sub1[128]) + digest_memory(&sub2[0], &sub2[128]));
 
  return 0;
}