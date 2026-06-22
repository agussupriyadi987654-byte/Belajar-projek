using System; 

class Program {
	static void Main() {
		//output pindah baris
		Console.WriteLine("Hello World");
		Console.WriteLine(@"
==============
SELAMAT DATANG
==============
Multibaris
______________
");
		
		int var1; //declare integer
		var1 = 13;
		String var2; //declare string
		var2 = "String";
		Console.WriteLine($"{var2}{var1}");
		var var3 = "Langsung"; // langsung isi
		Console.WriteLine(var3);

		//input
		Console.Write("Masukan Nama :");
		String nama = Console.ReadLine();

		Console.WriteLine("Halo {0}", nama);
	}
}
