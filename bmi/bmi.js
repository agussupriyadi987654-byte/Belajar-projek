// import readline/promises untuk input
const readline = require('readline/promises');
const {stdin: input, stdout: output} = require('process');
const rl = readline.createInterface({input, output});

// fungsi async
async function main() { 
	console.log("KALKULATOR BMI");
	console.log("==============");
	let berat = await rl.question("Masukan Berat anda (dalam kg) :"); // input pake await
	let tinggi = await rl.question("Masukan Tinggi anda (dalam m) :");
	if (berat == 0 || tinggi == 0) { 
		//jika salah satu nilai nol
		console.log("Nilai tidak bisa nol");
		rl.close()
		return;
	}
	let bmi = berat/(tinggi**2);
	console.log("Score bmi anda", bmi.toFixed(2));
	let status;
	if (bmi<18.5){
		status = "underweight";
	} else if (bmi<24.9) {
		status = "ideal";
	} else if (bmi<29.9) {
		status = "overweight";
	} else if (bmi >= 29.9) {
		status = "obesitas";
	} else {
		console.log("lu masukin apa kocak");
		rl.close();
		return;
	}
	console.log("Anda termasuk",status);
	rl.close();
}
main()
