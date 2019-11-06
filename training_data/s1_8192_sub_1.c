#include "header.h"

int out[8192] ALIGNED16;
int in1[8192] ALIGNED16;
int in2[8192] ALIGNED16;
__attribute__((noinline))
void example1 () {
  int i;

  for (i=0; i<8192; i++){
    out[i] = in1[i] -in2[i];
  }
}
int main(int argc,char* argv[]){
 
  init_memory(&out[0], &out[8192]);
  init_memory(&in1[0], &in1[8192]);
  init_memory(&in2[0], &in2[8192]);
  BENCH("Example1",   example1(), Mi*4/8192*256, digest_memory(&out[0], &out[8192]));
  
  
  return 0;
}