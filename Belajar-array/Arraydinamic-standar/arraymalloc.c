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
int main() {
	struct ArrayMelar teks;
	init_array(&teks);
	struct ArrayMelar tiks;
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
	for(int i=0;i<teks.ukuran;i++){free(teks.data[i]);}
	free(teks.data);
	for(int i=0;i<tiks.ukuran;i++){free(tiks.data[i]);}
	free(tiks.data);
	return 0;
}
