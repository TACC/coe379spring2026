#include <stdlib.h>
#include <stdio.h>

#include "omp.h"

FILE *get_file_handle( char* filename ) {
  FILE *inputfile = fopen(filename,"r");
  return inputfile;
}

int main( int argc,char **argv ) {

#pragma omp parallel
#pragma omp single
  {
    float x;
#pragma omp task depend(out:x)
    x = 3.14;
#pragma omp task depend(in:x)
    {
      FILE *inputfile = get_file_handle( argv[1] );
      int value;
      fscanf(inputfile,"%d",&value);
      printf("read: %d\n",value);
    }
  }

  return 0;
}
