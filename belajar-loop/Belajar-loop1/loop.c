/*
 * tantangan :
 * step harus positif
 *
 * Target :
 * Level1

 ****
 ***
 **
 * 

 * Level2
 
 1
 22
 333
 4444

 * Level3
 
 1
 12
 123
 1234

 */

#include <stdio.h>
int main() {
	int a = 4;
	for (int i = 0;i<a;i++) {
		for (int j=0; j<a-i;j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0;i<a;i++) {
                for (int j=0; j<=i;j++) {
                        printf("%d",i+1);
                }
		printf("\n");
        }
	printf("\n");
        for (int i = 0;i<a;i++) {
                for (int j=0; j<=i;j++) {
                        printf("%d",j+1);
                }
		printf("\n");
        }
	return 0;
}
