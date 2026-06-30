#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrayMelar{
	char **data;
	int kapasitas;
	int ukuran;
};


void init_array(struct ArrayMelar *arr){
	arr->ukuran = 0;
	arr->kapasitas = 2;
	arr->data = (char **)malloc(arr->kapasitas * sizeof(char *));
}

struct ArrayMelar g_temp;    

void push(struct ArrayMelar *arr, char *teksbaru) {
	if (arr->ukuran == arr-> kapasitas){
		arr->kapasitas *=2;
		arr->data = (char **)realloc(arr->data,arr->kapasitas * sizeof(char *));
	}
	arr->data[arr->ukuran] = malloc(strlen(teksbaru) + 1);
	strcpy(arr->data[arr->ukuran], teksbaru);
	arr -> ukuran++;
}

char *pop(struct ArrayMelar *arr){
	if (arr-> ukuran <= 0) {
		return "";
	}
	arr-> ukuran--;
	return arr->data[arr-> ukuran];
}
void reverse(struct ArrayMelar *arr){
	init_array(&g_temp);
	int banyak = arr->ukuran;
	for (int i=0;i<banyak;i++){ 
		char temp2[100];
		strcpy(temp2,pop(arr));
                push(&g_temp,temp2); 
	}
	arr-> data = g_temp.data;
	arr-> kapasitas = g_temp.kapasitas;
	arr-> ukuran = g_temp.ukuran;
	g_temp.data = NULL;
	g_temp.kapasitas = 0;
	g_temp.ukuran = 0;
}

char *cpop(struct ArrayMelar *arr, int index){
	init_array(&g_temp);
	static char ambil[100];
	strcpy(ambil, arr -> data[index]);
	reverse(arr);
        int banyak = arr->ukuran;
        for (int i=0;i<banyak;i++){
                char temp2[100];
                strcpy(temp2,pop(arr));
		if (i!=index){
                push(&g_temp,temp2);
		}
        }
        arr-> data = g_temp.data;
        arr-> kapasitas = g_temp.kapasitas;
        arr-> ukuran = g_temp.ukuran;
        g_temp.data = NULL;
        g_temp.kapasitas = 0;
        g_temp.ukuran = 0;
	return ambil;
}

void showlist(struct ArrayMelar *arr){
	for (int i=0;i<arr->ukuran;i++){
		printf("%d. %s\n",i+1,arr->data[i]);
	}
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

int len(struct ArrayMelar *arr){
	return arr->ukuran;
}
void kosong(struct ArrayMelar *arr){
	int panjang = len(arr);
	for(int i=0;i<panjang;i++){
		pop(arr);
	}
}

int main() {
	struct ArrayMelar stok;
	init_array(&stok);
	push(&stok,"Apel");
	push(&stok,"Pisang");
	push(&stok,"Mangga");
	push(&stok,"Brokoli");
	push(&stok,"Tomat");
	push(&stok,"Wortel");
	struct ArrayMelar keranjang;
	init_array(&keranjang);
	menukasir();
	char nama[100];
	int sudahbayar = 1;
	while(1){
		char pilih[100];
		strcpy(pilih, input("\nPilih Menu 1-6 :"));
		if (strcmp(pilih,"0")==0) menukasir();
		else if (strcmp(pilih,"1")==0) showlist(&stok);
		else if (strcmp(pilih,"2")==0) {
			push(&stok, input("Masukan nama barang :"));
			printf("Barang Sudah Dimasukan dalam stok.\n");
		}else if (strcmp(pilih,"3")==0) {
			if (sudahbayar==1){
				strcpy(nama, input("Masukan nama :"));
				printf("Keranjang baru dibuat\n");
				sudahbayar = 0;
			} else {
				printf("Kostumer sebelumny belum bayar.\n");
			}
		}else if (strcmp(pilih,"4")==0) {
			if (sudahbayar==1){
				printf("Keranjang baru, belum dibuat.\n");
				continue;
			}
			int index = atoi(input("Masukan index barang :"))-1;
			if (index<0 || index >=len(&stok)){
				printf("Barang di Index tersebut tidak ada.\n");
				continue;
			}
			char ambil[100];
			strcpy(ambil, cpop(&stok,index));
			push(&keranjang, ambil);
			printf("%s dimasukkan ke keranjang %s.\n",ambil,nama);
		}else if (strcmp(pilih,"5")==0) {
			if (sudahbayar==1){
				printf("Keranjang baru, belum dibuat.\n");
				continue;    
			}
			if (len(&keranjang)==0){
				printf("Keranjang masih kosong.\n");
				continue;
			}
			printf("Nama : %s\n",nama);
			showlist(&keranjang);
			printf("Bayar (y/n) :");
			char yn[2];
			scanf("%1s",yn);
			if (strcmp(yn,"y")==0) {
				sudahbayar = 1;
				kosong(&keranjang);
				printf("Terima kasih, sampai jumpa.\n\n");
			}
		}else if (strcmp(pilih,"6")==0) break;
		else printf("Menu tidak ada di pilihan.\n");
	}
	for(int i=0;i<stok.ukuran;i++){free(stok.data[i]);}
	free(stok.data);
	for(int i=0;i<keranjang.ukuran;i++){free(keranjang.data[i]);}
	free(keranjang.data);
	return 0;
}
