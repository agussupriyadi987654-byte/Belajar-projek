//ini komentar
/*ini komentar multi baris
 * buat dokumentasi
 * buat debugging beberapa kode langsung
 */

console.log("Hello world"); //output
console.log(`
=====================		
SELAMAT DATANG SEMUA
___________________
Ini output multi baris
____________________
`);

let var1 = 10; //ini variabel, nilai bisa diubah
const var2= 11; //ini konstanta,tetap nilai nya
let var3 = "Nilai";
console.log(var3+var1);//di js tidak usah konversi
var1 = 15; //mengubah nilai
console.log(var3, var1);
//var 2 = 15; //ini akan error

//input, pake readline/promises
const readline = require('readline/promises');
const {stdin: input, stdout: output} = require('process');
const rl = readline.createInterface({input, output});
/* karena js sifat nya asynchronus,
 * maka pake async function
 * terus pakai await untuk inputnya
 */
async function main() {
	let nama = await rl.question('siapa namamu?');
	console.log(`halo ${nama}`);
	rl.close()//ditutup ya,
	//nanti nginput terus kalau ngga ditutup

}
main()
