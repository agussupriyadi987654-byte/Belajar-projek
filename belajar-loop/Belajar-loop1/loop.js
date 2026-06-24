/*
 * tantangan :
 * step harus positif
 *
 * Target :
 * Level1

 ****
 ***
 **
 *
 
 * level2
 
 1
 22
 333
 4444

 * Level3
 1
 12
 123
 1234
 */
/** @type {number} */
let a = 4;
for (let i=0;i<a;i++) {
	for (let j=0;j<a-i;j++) {
		process.stdout.write("*");
	}
	console.log();
}
console.log()
for (let i=0;i<a;i++) {
	for (let j=0;j<=i;j++) {
		process.stdout.write(`${i+1}`);
        }
        console.log();
}
console.log()
for (let i=0;i<a;i++) {
	for (let j=0;j<=i;j++){
		process.stdout.write(`${j+1}`);
	}
	console.log();
}
