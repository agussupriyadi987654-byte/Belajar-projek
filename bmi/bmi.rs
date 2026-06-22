use std::io::{self, Write}; // untuk input

fn main() {
    println!("Kalkulator BMI");
    println!("===============");
    print!("Masukan Berat (dalam kg) :");
    io::stdout().flush().unwrap();//paksa print keluar langsung
    let mut berat = String::new();
    io::stdin().read_line(&mut berat).unwrap();
    // input pinjam kepemilikan variabel berat
    print!("Masukan Tinggi (dalam m) :"); // tinggi
    io::stdout().flush().unwrap();
    let mut tinggi = String::new();
    io::stdin().read_line(&mut tinggi).unwrap();


    let berat_angka:f32 = berat.trim().parse().unwrap_or(0.0); //berat dijadikan angka float
    let tinggi_angka:f32 = tinggi.trim().parse().unwrap_or(0.0); //tinggi dijadikan angka float
                                                         //jika salah satu nilainya salah atau nol
    if berat_angka == 0.0 || tinggi_angka == 0.0 {
        println!("Ngga boleh kocak !");
        return;
    }
    let bmi:f32  = berat_angka/tinggi_angka.powf(2.0);

    println!("Score bmi mu adalah {:.2}", bmi);
    let status;
    if bmi<18.5 { 
        status = "underweight";
    } else if bmi<24.9 {
        status = "ideal";
    } else if bmi<29.9 {
        status = "overweight";
    } else {
        status = "obesitas";
    }
    println!("Kamu termasuk {}", status);


}
