#include<stdio.h>
void main(){
	int i;
	for (i = 0; i < 10; i++) {
	  if (i == 4) {
	    break;
	  }
	  printf("%d\n", i);
	}
}
