


Imports System
module Program
sub Main()
	Dim a As Integer = 4
	Dim b As Integer = 1
	For i As Integer = 0 To a-1
		For j As Integer = 0 To i
			Console.Write(b)
			b=b+1
		Next j
		Console.WriteLine()
	Next i
	Console.WriteLine()
	For i As Integer = 0 To a*2-1 Step 2
		For j As Integer = 0 To a-i/2-1
			Console.Write(" ")
		Next j
		For j As Integer = 0 To i
			Console.Write("*")
		Next j
		Console.WriteLine()
	Next i
End sub
End Module
