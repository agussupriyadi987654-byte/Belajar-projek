#include <iostream>
#include <cmath>
#include <iomanip> //untuk std::format
int main() {
	std::cout<<"Kalkulator BMI\n";
	std::cout<<"==============\n";
	float berat;
	float tinggi;
	std::cout<<"Masukan berat (dalam kg) :";
	std::cin>>berat;
	std::cout<<"Masukan tinggi (dalam m) :";
	std::cin>>tinggi;
	if (berat == 0 || tinggi == 0) {
		std::cout<<"Nilai tidak boleh nol\n";
		return 0;
	}
	int bmi = berat/pow(tinggi,2);
	std::cout<<"Score BMI mu "<< std::fixed << std::setprecision(2) << bmi <<"\n";
	std::string status;
	if (bmi < 18.5) {
		status = "underweight";
	} else if (bmi < 24.9) {
		status = "ideal";
	} else if (bmi < 29.9) {
		status = "overweight";
	} else if (bmi > 29.9) {
		status = "obesitas";
	}
	std::cout<<"Kamu termasuk "<<status<<"\n";
	return 0;
}

