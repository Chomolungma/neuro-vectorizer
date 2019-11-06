
#include "header.h"
int out[2048] ALIGNED16;
__attribute__((noinline))
void example2a (int y) {
   int i;

   /* feature: support for unknown loop bound  */
   /* feature: support for loop invariants  */
   for (i=0; i< 2048 ; i++) {
      out[i] = y;
   }
}
int main(int argc,char* argv[]){
 
  init_memory(&out[0], &out[2048]);
  BENCH("Example2a",  example2a(2), Mi*4/2048*512, digest_memory(&out[0], &out[2048]));
  
  return 0;
}