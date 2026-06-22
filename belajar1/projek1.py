#ini komentar sebaris
"""
ini komentar multi baris
digunakan untuk dokumentasi
menjelaskan secara detail
dan debug kode yg banyak
"""

print("hello world") #output
print("""
=========
SELAMAT DATANG
_________
""")# output multibaris

# contoh variabel
var1 = 1 #tipe data integer
var2 = "halo" #tipe data string
var3 = 123.0 # tipe data float

print(var2+str(var1)) #penghubung
print(var2, var1) #pemisah
print(f"{var2} {var1}") #fstring

#output tanpa pindah baris
print("masukan nama :", end="") 

var4 = input() #input
print(f"Halo {var4}, selamat datang")
