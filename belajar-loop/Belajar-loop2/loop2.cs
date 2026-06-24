
/*
 * Level4
 
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
using System;

class Program{
	static void Main(){
		int a=4;
		int b=1;
		for(int i=0;i<a;i++){
			for(int j=0;j<=i;j++){
				Console.Write(b);
				b++;
			}
			Console.WriteLine();
		}
		Console.WriteLine();
		for(int i=0;i<2*a;i+=2){
			for(int j=0;j<a-i/2;j++){
				Console.Write(" ");
			}
			for(int j=0;j<=i;j++){
				Console.Write("*");
			}
			Console.WriteLine();
		}
	}
}
