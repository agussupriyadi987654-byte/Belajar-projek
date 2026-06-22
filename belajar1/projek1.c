//ini komentar
//
/* ini komentar multi baris
 * untuk debugging nonaktifkan kode banyak
 * untuk dokumentasi secara detail
 */
#include <stdio.h> //buat input output

int main() {
	printf("Hello world\n");//pindah baris
	printf("===============\nSELAMAT DATANG\n");
	printf("===============\n");/*ngga ada output
				    muti baris*/
	int var1 = 1; // variabel int
	char var2 = 'H'; // variabel karakter
	double var3 = 12.3; //float
	printf("ini int : %d,\nini char : %c,\nini float : %f\n", var1, var2, var3);
	char var4[50] = "Halo siapa namamu?";//ini str
	char var5[50]; //ini string buat input
	printf("%s",var4);
	scanf("%s", var5); //minta input
	printf("Halo %s/n", var5);
	return 0;//mengembalikan nilai 0
}
