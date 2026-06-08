//ini komentar
/* ini komentar multi baris
 * buat debugging
 * buat dokumentasi
 */
use std::io::{self, Write};// untuk input


fn main() { //harus ada main function
    println!("hello world"); //ini output
    println!("
=============
SELAMAT DATANG
_____________
Ini multibaris
");
    let var1 = "Halo"; //mirip const di js ngga bisa diubah
    let mut var2 = "Hai"; // mirip let di js
    println!("{} {}",var2, var1);// pake placeholder
    var2 = "Woy"; //diganti
    //var1 = "Woy" // ini akan error tapi bisa var1=var1+1
    println!("{} {}", var2, var1);
    let var3:i8 = 27; //akan membuat slot bilangan
                     //rentang -2⁷ sampai 2⁷
    println!("angka : {}", var3);

    print!("Masukan nama :"); //tanpa enter
    io::stdout().flush().unwrap();
    //input tidak keluar dulu
    let mut nama = String::new(); //bikin wadah variabel
    io::stdin().read_line(&mut nama).unwrap();
    /* outputnya ada dua kemungkinan, isi dan error
    .unwrap() buat ambil isi nya aja.
    */
    println!("Halo {}", nama);
}
