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

 *Level3

 1
 12
 123
 1234

 */
using System;
class Program {
	static void Main(){
		int a = 4;
		for(int i=0;i<a;i++) {
			for(int j=0;j<a-i;j++){
				Console.Write("*");
			}
			Console.WriteLine();
		}
		Console.WriteLine();
		for(int i=0;i<a;i++) {
			for(int j=0;j<=i;j++){
				Console.Write(i+1);
                        }
                        Console.WriteLine();
                }
		Console.WriteLine();
		for(int i=0;i<a;i++) {
			for(int j=0;j<=i;j++){
				Console.Write(j+1);
			}
			Console.WriteLine();
		}
	}
}
