#include "header.h"

int G[2048][512];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<2048-1; i+=2) {
     for (j=0; j<512-1; j+=2) {
       G[i][j] = x;
       G[i+1][j] = x;
       G[i][j+1] = x;
       G[i+1][j+1] = x;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&G[0][0], &G[0][512]);
  BENCH("Example8",   example8(8), 1024, digest_memory(&G[0][0], &G[0][512]));
 
  return 0;
}