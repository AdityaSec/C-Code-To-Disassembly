#include <stdio.h>
int main( int argc, char *argv[] )  {
   if( argc == 2 ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else {
      printf("Please provide argument.\n");
   }
}