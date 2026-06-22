#include <stdio.h>
#include <math.h>

int main() {
	printf("Kalkulator BMI\n");
	printf("==============\n");
	float berat;
	float tinggi;
	printf("Masukan berat (dalam kg) :");
	scanf("%f", &berat);
	printf("Masukan tinggi (dalam m) :");
	scanf("%f", &tinggi);
	if (berat == 0 || tinggi == 0) {
		printf("nilai tidak boleh nol\n");
		return 0;
	}
	float bmi = berat/pow(tinggi,2);
	printf("Score bmi mu : %.2f\n",bmi);
	char status[15];
	if (bmi < 18.5) {
		strcpy(status, "underweight");
	} else if (bmi < 24.9) {
		strcpy(status, "ideal");
	} else if (bmi < 29.9) {
		strcpy(status, "overweight");
	} else {
		strcpy(status, "obesitas");
	}
	printf("Kamu termasuk %s\n",status);
	return 0;
}
