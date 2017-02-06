#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void customhead(int w, int h, int lim, char* buff){
  strcpy(buff,"");
  snprintf(buff,64,"P3 %d %d %d ", w,h,lim);
}

void pixel(int r, int g, int b, char* buff){
  strcpy(buff,"");
  snprintf(buff,64,"%d %d %d ",r,g,b);
}

int main(){
  int w = 500;
  int h = 500;
  int lim = 312;
  int countw = 0;
  int counth = 0;
  
  FILE *newim = fopen("image.ppm", "w");
  char buff[64];
  
  customhead(w,h,lim,&buff);  
  fprintf(newim,buff);
  
  while(counth < h){
    while (countw < w){
      pixel(counth, countw, 0 ,&buff);
      fprintf(newim,buff);
      countw++;
    }
    countw = 0;
    counth++;
  }
  
  fprintf(newim,"\n");
  printf("image made!\n");
}
