#include<stdio.h>    
int main(){    
	int number=0;    
	printf("enter a number:");    
	scanf("%d",&number);     
	if(number==10){    
		printf("number is equals to 10");    
	}    
	else if(number==50){    
		printf("number is equal to 50");    
	}    
	else if(number==100){    
		printf("number is equal to 100");    
	}    
	else{    
		printf("number is not equal to 10, 50 or 100");    
	}    
	return 0;  
}   
