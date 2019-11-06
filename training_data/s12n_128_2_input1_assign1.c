#include "header.h"

short input1[128];
short input2[128];
int   assign1[128] ALIGNED16;
int   assign2[128] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ input1, short *__restrict__ input2, int* __restrict__ assign1, int* __restrict__ assign2) {
  int i;
  for (i = 0; i < 128; i+=2) {
    assign1[i] = (int) input1[i];
    assign2[i] = (int) input2[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&assign1[0], &assign1[128]);
  init_memory(&assign2[0], &assign2[128]);
  init_memory(&input1[0], &input1[128]);
  init_memory(&input2[0], &input2[128]);
  BENCH("Example10b", example10b(input1,input2,assign1,assign2), Mi*4/128*512, digest_memory(&assign1[0], &assign1[128])+digest_memory(&assign2[0], &assign2[128]));
 
  return 0;
}