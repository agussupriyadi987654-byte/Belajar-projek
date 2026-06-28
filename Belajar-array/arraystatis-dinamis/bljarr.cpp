#include <iostream>
#include <string>

std::string arraykaku[100]; //array kaku global besar
int pointerlen = 0; // panjang array global yg terisi
int awalan[10] = {-1}; //nyimpan arr yg make array ini

int newarray(std::string newarr[]){ //nyimpan arr ke global
	//loop buat nyari arr awalan yg kosong
	//jika ada yang kosong, isi.
	//-1 sebagai patokan awal posisi kosong
	int i=0;
	while(1){
		if (awalan[i]>=0) {i++;continue;}
		else break;
	}
	awalan[i+2]=-1; //pindahkan -1 ke belakang lg
	awalan[i] = pointerlen;//isinya: letak awal data

	//loop buat nyimpen array baru ke arraykaku
        //nyimpen satu-satu, berhenti ktika ""
	int j = 0;
	while(newarr[j] != ""){
		arraykaku[pointerlen] = newarr[j];
		j++;
		pointerlen++;
	}
	awalan[i+1] = pointerlen-awalan[i];
	// simpan di awalan [genap, ganjil, genap ganjil]
	// genap(0) = awal data dimulai di array kaku
	// ganjil(1) = banyak data
	return i; //ngembaliin letak data disimpan
}

void push(int arr, std::string tambahan){ //nambah 
   if (awalan[arr+1]==0) awalan[arr] = pointerlen;
	int akhir = awalan[arr]+awalan[arr+1];
	// akhir = awal data +banyak data
	// akhir, ini pointer buat nambah data
	//isi di akhir data yg dipake dengan tambahan
	std::string temp = tambahan;
	//looping buat nggeser data ke kanan
	for (int i=akhir;i<=pointerlen;i++){
		std::string j = arraykaku[i];
		arraykaku[i] = temp;
		temp = j;
	}
	//banyak data local dan global +1
	awalan[arr+1]++;
	pointerlen++;
	//looping buat nambah 1 awal data (genap)
	int j = 0;
	while(1){
                if (awalan[j]>=0) {
			if (awalan[j] > awalan[arr] && j%2==0) awalan[j]++;
			j++;
		}
                else break;
	}
}

std::string pop(int arr){ //ambil atau pop
    int akhir = awalan[arr] + awalan[arr+1] - 1;
    // akhir = awal+banyak-1
    // pointer buat ngambil data, jadi -1
    static std::string hasil;
    //jika banyak data di array = 0, alias kosong
    if(awalan[arr+1] <= 0){
	hasil = "";
        return hasil;
    }
    // hasil = data yang mau diambil
    hasil = arraykaku[akhir];
    //looping geser array ke kiri, lebih gampang
    for(int i = akhir; i < pointerlen - 1; i++){
        arraykaku[i] = arraykaku[i+1];
    }
    //banyak data local dan global -1
    pointerlen--;
    awalan[arr+1]--;
    // loop utk kurangi 1 stiap awal data
    for (int j = 0; awalan[j] >= 0; j++){
        if (awalan[j] > awalan[arr] && j % 2 == 0) awalan[j]--;
    }
    return hasil;
}

void showlist(int arr){
	//buat ngprint doang
	int awal = awalan[arr];
	int banyak = awalan[arr+1];
	std::cout<<"{";
	for (int i=0;i<banyak;i++){
		std::cout<<arraykaku[awal+i]<<",";
	}
	std::cout<<"}\n";
}
int main(){
	std::string temparr[] = {""};
	int arraybuah = newarray(temparr);
	std::string temparr1[] = {"tomat","wortel","brokoli",""};
	int arraysayur = newarray(temparr1);
	showlist(arraybuah);
	push(arraybuah, "pisang");
	push(arraybuah, "apel");
	showlist(arraysayur);
	push(arraybuah, "mangga");
	showlist(arraybuah);
	std::string ambil = pop(arraybuah);
	std::cout<<ambil<<"\n";
	showlist(arraybuah);
	showlist(arraysayur);
	ambil = pop(arraysayur);
	std::cout<<ambil<<"\n";
        showlist(arraysayur);
	return 0;
}
