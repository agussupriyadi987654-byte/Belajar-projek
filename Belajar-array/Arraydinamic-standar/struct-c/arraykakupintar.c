#include <stdio.h>
#include <string.h>

struct VektorPintar{
	char data[50][100];
	int len;
};

void init_array(struct VektorPintar *v){v->len = 0;}

void push(struct VektorPintar *v, char *teksbaru) {
	strcpy(v->data[v->len],teksbaru);
	v->len++;
}

char *pop(struct VektorPintar *v){
	v->len--;
	return v-> data[v->len];
}
int main() {
	struct VektorPintar teks;
	init_array(&teks);
	struct VektorPintar tiks;
        init_array(&tiks);
	push(&teks, "Apel");
	push(&tiks, "Brokoli");
	push(&teks, "Mangga");
	printf("Buah 1 : %s\n", teks.data[0]);
	printf("Buah 2: %s\n", teks.data[1]);
	printf("Sayur 1: %s\n", tiks.data[0]);
	printf("Ambil Buah %s\n", pop(&teks));
	push(&teks, "Rambutan");
	printf("Buah 2: :%s\n", teks.data[1]);
	return 0;
}
