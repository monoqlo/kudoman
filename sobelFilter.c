#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_inout.h"
#define N 1

main(){
    unsigned char image1[256][256], image2[256][256];
    int i, j, i2, j2, k, l, number;
    //int gh[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    //int gv[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    int gh[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gv[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    read_image(image1, 65536, "lena");

    for(i=0; i<256; i++)
        for(j=0; j<256; j++){
            int valFx = 0;
            int valFy = 0;
            //int m = 0;
            for(k=-N; k<=N; k++) {
                for(l=-N; l<=N; l++){
                    i2 = i + k;
                    j2 = j + l;
                    if(i2<0 || i2>255 || j2<0 || j2>255){
                        //m++;
                    } else {
                        //配列に画素値を確保
                        //valFx += image1[i2][j2] * gv[m];
                        //valFy += image1[i2][j2] * gh[m];

                        valFx += image1[i2][j2] * gv[k+1][l+1];
                        valFy += image1[i2][j2] * gh[k+1][l+1];
                        //m++;
                    }
                }
            }
            int tmp = sqrt(valFx * valFx + valFy * valFy);
            if(tmp > 255)
                image2[i][j] = 255;
            else
                image2[i][j] = tmp;

        }
    
    write_image(image2, 65536, "out");
}

        
