//ini komentar
/*ini multibaris
 * buat debugging
 * buat gitu lah
 */
#include <iostream> //input output
#include <string> //string

int main() {
	std::cout <<"Hello world" <<std::endl;
	std::cout <<R"(
=============
SELAMAT DATANG
______________
Multibaris
)"<<std::endl;

	int var1; //declare dulu
	var1 = 90; // sama kayak C lah
	std::string var2;
	var2 = "Halo "; //string
	std::cout <<"Hai "<<var2<<var1<<std::endl;

	//input
	std::cout << "Masukan Nama :";
	std::string nama;//deklare
	std::cin >> nama;
	std::cout << "Halo " << nama <<" apa kabar?";

	return 0;
}
