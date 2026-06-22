Imports System
Module Program
Sub Main
	Console.WriteLine("Kalkulator BMI")
	Console.WriteLine("==============")
	Console.Write("Masukan Berat (dalam kg) :")
	Dim berat As Double
	berat = Double.Parse(Console.ReadLine())
	Console.Write("Masukan Tinggi (dalam m) :")
	Dim tinggi As Double
	tinggi = Double.Parse(Console.ReadLine())
	If berat = 0 Or tinggi = 0 Then
		Console.WriteLine("Nilai ngga bisa nol")
	Else
		Dim bmi As Double = berat/tinggi^2
		Console.WriteLine("Score BMI kamu " & bmi.ToString("2F"))
		Dim status As String
		If bmi < 18.5 Then
			status = "Underweight"
		ElseIf bmi < 24.9 Then
			status = "Ideal"
		ElseIf bmi < 29.9 Then
			status = "Overweight"
		Else 
			status = "Obesitas"
		End If
		Console.WriteLine("Kamu termasuk "& status)
	End If
End Sub
End Module
