#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

char arraykaku[100][100]; //array kaku global besar
int pointerlen = 0; // panjang array global yg terisi
int awalan[10] = {-1}; //nyimpan arr yg make array ini
		       
int newarray(char *newarr[]){ //nyimpan arr ke global
	//loop buat nyari arr awalan yg kosong
	//jika ada yang kosong, isi.
	//-1 sebagai patokan awal posisi kosong
	//if
	int i=0;
	while(true){
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
	if(awalan[arr+1]==0){awalan[arr]=pointerlen;}
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
	while(true){
                if (awalan[j]>=0) {
			if (awalan[j]>awalan[arr] && j%2==0) awalan[j]++;
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
        if (awalan[j]>awalan[arr]  && j % 2 == 0) awalan[j]--;
    }
    return hasil;
}
void showlist(int arr){
	//buat ngprint doang
	int awal = awalan[arr];
	int banyak = awalan[arr+1];
	printf("== DAFTAR ==\n");
	if (banyak==0) printf("Kosong\n");
	for (int i=0;i<banyak;i++){
		printf("%d. %s\n",i+1,arraykaku[awal+i]);
	}
}
void reverse(int arr){
	int banyak = awalan[arr+1];
	int temp = newarray((char*[]){""});
	for (int i=0;i<banyak;i++){ 
		char temp2[100];
		strcpy(temp2,pop(arr));
                push(temp,temp2); 
	}
        awalan[arr] = awalan[temp];
	awalan[arr+1] = awalan[temp+1];
	awalan[temp] = -1;
	awalan[temp+1] = 0;
}
char* cpop(int arr, int index){
	static char hasil[100];
	strcpy(hasil, arraykaku[awalan[arr]+index]);
	reverse(arr);
        int banyak = awalan[arr+1];
        int temp = newarray((char*[]){""});
	char temp2[100];
	for (int i=0;i<banyak;i++){
                strcpy(temp2,pop(arr));
                if (i!=index){  
			push(temp,temp2);
                }
        }   
        awalan[arr] = awalan[temp];
        awalan[arr+1] = awalan[temp+1];
        awalan[temp] = -1; 
	awalan[temp+1] = 0;
	return hasil;
}
char* input(char prompt[]){
	printf("%s",prompt);
	static char temp[100];
	scanf("%99s",temp);
	return temp;
}

void menukasir(){
	printf("===== MENU KASIR =====\n");
	printf("0. Tampilkan menu\n"); 
	printf("1. Lihat Stock\n");
        printf("2. Tambah Stock\n");
        printf("3. Keranjang Baru\n"); 
	printf("4. Masukan stok ke keranjang\n");  
	printf("5. Cetak Struk dan Bayar\n"); 
	printf("6. Keluar\n");
}

int len(int arr){
	return awalan[arr+1];
}
void kosong(int arr){
	int panjang = len(arr);
	for(int i=0;i<panjang;i++){
		pop(arr);
	}
}

int main(){
	int stok = newarray((char*[]){"Apel","Pisang","Mangga","Brokoli","Tomat","Wortel",""});
	int keranjang = newarray((char*[]){""});
	menukasir();
	char nama[100];
	int sudahbayar = true;
	while(true){
		char pilih[100];
		strcpy(pilih, input("\nPilih Menu 1-6 :"));
		if (strcmp(pilih,"0")==0) menukasir();
		else if (strcmp(pilih,"1")==0) showlist(stok);
		else if (strcmp(pilih,"2")==0) {
			push(stok, input("Masukan nama barang :"));
			printf("Barang Sudah Dimasukan dalam stok.\n");
		}else if (strcmp(pilih,"3")==0) {
			if (sudahbayar==true){
				strcpy(nama, input("Masukan nama :"));
				printf("Keranjang baru dibuat\n");
				sudahbayar = false;
			} else {
				printf("Kostumer sebelumny belum bayar.\n");
			}
		}else if (strcmp(pilih,"4")==0) {
			if (sudahbayar==true){
				printf("Keranjang baru, belum dibuat.\n");
				continue;
			}
			int index = atoi(input("Masukan index barang :"))-1;
			if (index<0 || index >=len(stok)){
				printf("Barang di Index tersebut tidak ada.\n");
				continue;
			}
			char ambil[100];
			strcpy(ambil, cpop(stok,index));
			push(keranjang, ambil);
			printf("%s dimasukkan ke keranjang %s.\n",ambil,nama);
		}else if (strcmp(pilih,"5")==0) {
			if (sudahbayar==true){                                                                          printf("Keranjang baru, belum dibuat.\n");                                              continue;                                                                       }
			if (len(keranjang)==0){
				printf("Keranjang masih kosong.\n");
				continue;
			}
			printf("Nama : %s\n",nama);
			showlist(keranjang);
			printf("Bayar (y/n) :");
			char yn[2];
			scanf("%1s",yn);
			if (strcmp(yn,"y")==0) {
				sudahbayar = true;
				kosong(keranjang);
				printf("Terima kasih, sampai jumpa.\n\n");
			}
		}else if (strcmp(pilih,"6")==0) break;
		else printf("Menu tidak ada di pilihan.\n");
	}
	return 0;
	
}
