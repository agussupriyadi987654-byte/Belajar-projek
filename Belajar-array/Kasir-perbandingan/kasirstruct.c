#include <stdio.h>
#include <string.h>

struct VektorPintar{
	char data[50][100];
	int len;
};


void init_array(struct VektorPintar *v){v->len = 0;}
struct VektorPintar g_temp;
void push(struct VektorPintar *v, char *teksbaru) {
	strcpy(v->data[v->len],teksbaru);
	v->len++;
}

char *pop(struct VektorPintar *v){
	v->len--;
	return v-> data[v->len];
}
void reverse(struct VektorPintar *v){
	init_array(&g_temp);
	int banyak = v->len;
	for (int i=0;i<banyak;i++){ 
		char temp2[100];
		strcpy(temp2,pop(v));
                push(&g_temp,temp2); 
	}
	v-> len = g_temp.len;
	for(int i=0;i<banyak;i++){
                strcpy(v->data[i],g_temp.data[i]);
		strcpy(g_temp.data[i],"");
        }
	g_temp.len = 0;
}
char *cpop(struct VektorPintar *v, int index){
        init_array(&g_temp);
	static char ambil[100];
	strcpy(ambil, v-> data[index]);
	reverse(v);
        int banyak = v->len;
        for (int i=0;i<banyak;i++){
                char temp2[100];
                strcpy(temp2,pop(v));
		if (i!=index){
                push(&g_temp,temp2);
		}
	}
	v-> len = g_temp.len;
        for(int i=0;i<banyak;i++){
		strcpy(v->data[i],g_temp.data[i]);
		strcpy(g_temp.data[i],"");
	}
        g_temp.len = 0;
	return ambil;
}

void showlist(struct VektorPintar *v){
	for (int i=0;i<v->len;i++){
		printf("%d. %s\n",i+1,v->data[i]);
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

int len(struct VektorPintar *v){
	return v->len;
}
void kosong(struct VektorPintar *v){
	int panjang = len(v);
	for(int i=0;i<panjang;i++){
		pop(v);
	}
}


int main() {
	struct VektorPintar stok;
	init_array(&stok);
	push(&stok,"Apel");
	push(&stok,"Pisang");
	push(&stok,"Mangga");
	push(&stok,"Brokoli");
	push(&stok,"Tomat");
	push(&stok,"Wortel");
	struct VektorPintar keranjang;
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
	return 0;
}
