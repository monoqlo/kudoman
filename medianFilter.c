#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_inout.h"
#define N 1

/* ソート関数 */
int int_sort( const void * a , const void * b ) {
  /* 引数はvoid*型と規定されているのでint型にcastする */
  if( *( int * )a < *( int * )b ) {
    return -1;
  }
  else
  if( *( int * )a == *( int * )b ) {
    return 0;
  }
  return 1;
}

main(){
    unsigned char image1[256][256], image2[256][256];
    int i, j, i2, j2, k, l, number;
    
    read_image(image1, 65536, "lenad");

    for(i=0; i<256; i++)
        for(j=0; j<256; j++){
            number = (2 * N + 1) * (2 * N + 1);
            int valArray[(2 * N + 1) * (2 * N + 1)];
            int m = 0;
            for(k=-N; k<=N; k++) {
                for(l=-N; l<=N; l++){
                    i2 = i + k;
                    j2 = j + l;
                    if(i2<0 || i2>255 || j2<0 || j2>255){
                        number = number-1;
                    } else {
                        //配列に画素値を確保
                        valArray[m] = image1[i2][j2];
                        m++;
                    }
                }
            }
            // 大きい順にソートして中央値を取る
            qsort(( void * )valArray , number , sizeof( valArray[0] ), int_sort );
            image2[i][j] = valArray[number/2 +1];

        }
    
    write_image(image2, 65536, "out");
}

        
