-- ini komentar
--[[ ini komentar multibaris
  untuk dokumentasi
  untuk debugging
  dan semacamnya
  ]]

print("Hello World") --kayak python
print([[
================
SELAMAT DATANG
===============
]]) -- ini output multibaris

var1 = 10 -- ini variabel global
local var2 = 15 -- ini variabel local
var3 = "Halo" -- ini string

print(var3..var1) -- pake pemisah .. bukan koma

io.write("Masukan nama :") --output baris tetap
nama = io.read()

print("Halo"..nama)


