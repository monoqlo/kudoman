/*     include file for data input and output for M09
       (jouhou-media-sousei gakurui 3-nensei jikken)
                                 by Hiroyuki Kudo        */

#include	<stdio.h>
#include	<stdlib.h>

read_image(image,size,fname) 
unsigned char 	*image;
int		size;
char    	*fname;	
{
   FILE	*fp;

   if((fp=fopen(fname,"r"))==NULL){
      printf("read_image: Can't open file %s\n", fname);
      exit(1);
   }
   if(fread(image,sizeof(unsigned char),size,fp)<1){
      printf("fread: Can't read data\n");
      exit(1);
   }
   fclose(fp);
}

write_image(image,size,fname)  
unsigned char	*image;
char		*fname;
int		size;
{
   FILE	*fp;

   if((fp=fopen(fname,"w"))==NULL){
      printf("fopen: Can't open file %s\n", fname);
      exit(1);
   }
   if (fwrite(image,sizeof(unsigned char),size,fp)<0){
      printf("fwrite: Can't write data to file %s\n",fname);
      exit(1);
   }
   fclose(fp);
}

read_proj(proj,fname) 
char         *fname;	
float        *proj;
{
   FILE	*fp;

   if((fp=fopen(fname,"r"))==NULL){
      printf("read_image: Can't open file %s\n", fname);
      exit(1);
   }
   if(fread(proj,sizeof(float),600*256,fp)<1){
      printf("fread: Can't read data\n");
      exit(1);
   }
   fclose(fp);
}
