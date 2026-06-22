using System;
class Program{
	static void Main() {
		Console.WriteLine("Kalkulator BMI");
		Console.WriteLine("==============");
		Console.Write("Masukan Berat (dalam kg) :");
		float berat = float.Parse(Console.ReadLine());
		Console.Write("Masukan Tinggi (dalam m) :");
		float tinggi = float.Parse(Console.ReadLine());
		if (berat == 0 || tinggi == 0) {
			Console.WriteLine("Nilai tidak bisa nol");
			return;
		}
		float bmi = (float)(berat/Math.Pow(tinggi, 2));
		Console.WriteLine("Score BMI mu {0}",bmi.ToString("F2"));
		string status;
		if (bmi < 18.5) {
			status = "underweight";
		} else if (bmi < 24.9) {
			status = "ideal";
		} else if (bmi < 29.9) {
			status = "overweight";
		} else {
			status = "obesitas";
		}
		Console.WriteLine("Kamu termasuk {0}", status);
		
	}
}
