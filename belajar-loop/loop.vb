'
'target :
'level 1
'****
'***
'**
'*
'
'Level2
'1
'22
'333
'4444
'
''Level3
'1
'12
'123
'1234

Imports System
Module Program
Sub Main()
	Dim a As Integer = 3
	For i As Integer = 0 To a
		For j As Integer = 0 To a-i
			Console.Write("*")
		Next j
		Console.WriteLine()
	Next i
	Console.WriteLine()
	For i As Integer = 0 To a
                For j As Integer = 0 To i
                        Console.Write(i+1)
                Next j
                Console.WriteLine()
        Next i
	Console.WriteLine()
        For i As Integer = 0 To a
                For j As Integer = 0 To i
                        Console.Write(j+1)                       
		Next j
                Console.WriteLine()
        Next i
End Sub
End Module


