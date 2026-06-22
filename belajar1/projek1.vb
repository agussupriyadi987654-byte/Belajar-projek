Imports System

Module Program
Sub Main()
	'Ini komentar
	'Ngga ada multibaris, sedih
	Console.WriteLine("Halo") 'ini output
	Console.WriteLine("Selamat" & vbLf & "Datang") 'ngga ada multibaris

	Dim var1 As String 'Variabel string
	var1 = "Halo" 
	Dim var2 As Integer
	var2 = 14
	Console.WriteLine(var1 & var2.ToString())
	'Output variabel, ubah tipe data ke str
	'.ToString() untuk VB Net
	'CStr(var) untuk VBA
	'Ngga bisa dibalik

	Console.Write("Masukan Nama :") 'tanpa enter
	Dim nama As String
	nama = Console.ReadLine() 'input

	Console.WriteLine("Halo " & nama)
End Sub
End Module
