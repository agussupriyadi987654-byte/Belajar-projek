#include <stdio.h>
#include <string.h>

char arraykaku[100][100]; //array kaku global besar
int pointerlen = 0; // panjang array global yg terisi
int awalan[10] = {-1}; //nyimpan arr yg make array ini

int newarray(char *newarr[]){ //nyimpan arr ke global
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
	while(strcmp(newarr[j],"") != 0){
		strcpy(arraykaku[pointerlen],newarr[j]);
		j++;
		pointerlen++;
	}
	awalan[i+1] = pointerlen-awalan[i];
	// simpan di awalan [genap, ganjil, genap ganjil]
	// genap(0) = awal data dimulai di array kaku
	// ganjil(1) = banyak data
	return i; //ngembaliin letak data disimpan
}

void push(int arr, char *tambahan){ //nambah 
   if (awalan[arr+1]==0) awalan[arr] = pointerlen;
	int akhir = awalan[arr]+awalan[arr+1];
	// akhir = awal data +banyak data
	// akhir, ini pointer buat nambah data
	char temp[100];
	//looping buat nggeser data ke kanan
	//isi di akhir data yg dipake dengan tambahan
	strcpy(temp, tambahan);
	for (int i=akhir;i<=pointerlen;i++){
		char j[10];
		strcpy(j, arraykaku[i]);
		strcpy(arraykaku[i], temp);
		strcpy(temp, j);
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

char* pop(int arr){ //ambil atau pop
    int akhir = awalan[arr] + awalan[arr+1] - 1;
    // akhir = awal+banyak-1
    // pointer buat ngambil data, jadi -1
    static char hasil[100];
    //jika banyak data di array = 0, alias kosong
    if(awalan[arr+1] <= 0){
	strcpy(hasil, "");
        return hasil;
    }
    // hasil = data yang mau diambil
    strcpy(hasil, arraykaku[akhir]);
    //looping geser array ke kiri, lebih gampang
    for(int i = akhir; i < pointerlen - 1; i++){
        strcpy(arraykaku[i], arraykaku[i+1]);
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
	printf("{");
	for (int i=0;i<banyak;i++){
		printf("%s,",arraykaku[awal+i]);
	}
	printf("}\n");
}
int main(){
	int arraybuah = newarray((char*[]){""});
	int arraysayur = newarray((char*[]){"tomat","wortel","brokoli",""});
	showlist(arraybuah);
	push(arraybuah, "pisang");
	push(arraybuah, "apel");
	showlist(arraysayur);
	push(arraybuah, "mangga");
	showlist(arraybuah);
	char ambil[100];
	strcpy(ambil,pop(arraybuah));
	printf("%s\n",ambil);
	showlist(arraybuah);
	showlist(arraysayur);
	strcpy(ambil,pop(arraysayur));
	printf("%s\n",ambil);
        showlist(arraysayur);
	return 0;
}
