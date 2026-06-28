

//VARIABEL GLOBAL RUST TIDAK AMAN, CARA PAKAI NYA :
// 1. DEFINISIKAN DENGAN static bukan let
// 2. NAMA VARIABEL GLOBAL UPPERCASE
// 3. PANGGIL DALAM blok unsafe{...}
//
// Tambahab = untuk angka sebagai index, kita pakai usize(untuk >=10)
static mut ARRAYKAKU: [String; 100] = [const { String::new() }; 100];
// array kaku global besar
static mut POINTERLEN: usize = 0; // panjang array global yg terisi
static mut AWALAN: [usize; 10] = [101; 10];
// nyimpen arr yg pake array ini


fn newarray(newarr: &[&str]) -> usize { 
    // Nyimpen array ke global, aksesnya harus unsafe
    unsafe {
        // loop buat nyari arr awalan yg kosong
        // jika ada yang kosong isi
        // 101 sebagai patokan, usize ngga bisa negatif
        let mut i: usize = 0;
        loop {
            if AWALAN[i] < 101 {i += 1;continue;}
            else {break;}
        }
        
        AWALAN[i + 2] = 101; //pindahkan 101 ke belakang 
        
        AWALAN[i] = POINTERLEN; // isinya: letak awal data
        // loop buat nyimpen array baru ke arraykaku
        // berhenti kalau ada ""
        let mut j: usize = 0;
        while newarr[j] != "" {
            ARRAYKAKU[POINTERLEN] = newarr[j].to_string();
            j += 1;
            POINTERLEN += 1;
        }
        AWALAN[i + 1] = POINTERLEN - AWALAN[i];
        //awalan [a,b,a,b]
        //a = awalan data diambil dr arraykaku
        //b = banyak data
        i // ngembaliin letak data disimpan
    }
}

fn push(arr: usize, tambahan: &str) { //nambah
    unsafe {
        if AWALAN[arr+1]==0 {AWALAN[arr] = POINTERLEN;}
        let akhir: usize = AWALAN[arr] + AWALAN[arr + 1];
        //akhir : pointer utk nambah data
        let mut temp = tambahan.to_string();
        // looping buat nggeser data ke kanan
        for i in akhir..=POINTERLEN {
            let j = ARRAYKAKU[i].clone();
            ARRAYKAKU[i] = temp;
            temp = j;   
        }
        
        // banyak data local dan global +1
        AWALAN[arr + 1] += 1;
        POINTERLEN += 1;
        
        // looping buat nambah 1 awal data(genap) stelah data saat ini
        let mut j: usize = 0;
        loop {
            if j < 10 && AWALAN[j] < 101 {
                if AWALAN[j] > AWALAN[arr] && j % 2 == 0 {
                    AWALAN[j] += 1;
                }
                j += 1;
            } else {break;}
        }
    }
}

fn pop(arr:usize)->String{ //ambil atau pop
    let hasil;
    unsafe {
        let akhir: usize= AWALAN[arr] + AWALAN[arr+1] - 1;
        //pointer buat ngambil data, jadi -1
        //jika banyak data di array = 0, alias kosong
        if AWALAN[arr+1] <= 0 {
            hasil = "".to_string();
            return hasil;
        }
        // hasil = data yang mau diambil
        hasil = ARRAYKAKU[akhir].clone();
        //looping geser array ke kiri, lebih gampang
        for i in akhir..(POINTERLEN - 1){
            ARRAYKAKU[i] = ARRAYKAKU[i+1].clone();
        }
        //banyak data local dan global -1
        POINTERLEN-=1;
        AWALAN[arr+1]-=1;
        // loop utk kurangi 1 stiap awal data
        let mut j: usize = 0;
        loop {
            if j < 10 && AWALAN[j] < 101 {
                if AWALAN[j] > AWALAN[arr] && j % 2 == 0 {
                    AWALAN[j] -= 1;
                }
                j += 1;
            } else {break;}
        }
    }
    hasil
}

fn showlist(arr: usize) { // buat ngprint doang
    unsafe {
        let awal: usize = AWALAN[arr];
        let banyak: usize = AWALAN[arr + 1];
        print!("[");
        for i in 0..banyak {
            print!("{},", ARRAYKAKU[awal + i]);
        }
        print!("]\n");
    }
}

fn main() {
    let arraybuah: usize = newarray(&[""]);
    let arraysayur: usize = newarray(&["tomat", "wortel", "brokoli", ""]); 
    showlist(arraybuah); 
    push(arraybuah, "pisang");
    push(arraybuah, "apel");
    
    showlist(arraysayur);
    push(arraybuah, "mangga");
    
    showlist(arraybuah);
    
    let mut ambil = pop(arraybuah);
    println!("{}",ambil);
    showlist(arraybuah);
    showlist(arraysayur);
    ambil = pop(arraysayur);
    println!("{}",ambil);
    showlist(arraysayur);
}
