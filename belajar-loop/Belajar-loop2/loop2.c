/*
 * Level 4
 
 1
 23
 456
 78910

 *Level 5

    *
   ***
  *****
 *******

 */

#include <stdio.h>

int main(){
	int a = 4;
	int b = 1;
	for(int i=0;i<a;i++){
		for(int j=0;j<=i;j++){
			printf("%d",b);
			b++;
		}
		printf("\n");
	}
	printf("\n");
	for (int i=0;i<a*2;i+=2){
		for(int j=0;j<a-i/2;j++){
                        printf(" ");
                }
		for(int j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
