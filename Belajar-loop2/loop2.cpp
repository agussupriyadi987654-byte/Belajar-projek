
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
#include <iostream>

int main(){
	int a=4;
	int b=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<=i;j++){
			std::cout<<b;
			b++;
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
	for(int i=0;i<2*a;i+=2){
		for(int j=0;j<a-i/2;j++){
			std::cout<<" ";
		}
		for(int j=0;j<=i;j++){
			std::cout<<"*";
		}
		std::cout<<"\n";
	}
	return 0;
}

