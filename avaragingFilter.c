#include <stdio.h>
#include <math.h>
#include "data_inout.h"
#define N 1

main(){
    unsigned char image1[256][256], image2[256][256];
    int i, j, i2, j2, k, l, val, number;

    read_image(image1, 65536, "lenad");

    for(i=0; i<256; i++)
        for(j=0; j<256; j++){
            val = 0;
            number = (2 * N + 1) * (2 * N + 1);
            for(k=-N; k<=N; k++)
                for(l=-N; l<=N; l++){
                    i2 = i + k;
                    j2 = j + l;
                    if(i2<0 || i2>255 || j2<0 || j2>255)
                        number = number-1;
                    else
                        val = val + image1[i2][j2];
                }
            image2[i][j] = (unsigned char)((float)val / (float)number + 0.5);
        }
    
    write_image(image2, 65536, "out");
}

        
