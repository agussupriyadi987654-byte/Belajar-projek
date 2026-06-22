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
 
 * level2
 
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
#include <iostream>
int a = 4;
int main() {
	for(int i=0;i<a;i++){
		for(int j=0;j<a-i;j++){
			std::cout<<"*";
		}
		std::cout <<"\n";
	}
	std::cout <<"\n";
	for(int i=0;i<a;i++){
		for(int j=0;j<=i;j++){
			std::cout<<i+1;
		}
		std::cout <<"\n";
        }
	std::cout <<"\n";
        for(int i=0;i<a;i++){
		for(int j=0;j<=i;j++){
			std::cout<<j+1;
		}
		std::cout <<"\n";
	}
	return 0;
}
