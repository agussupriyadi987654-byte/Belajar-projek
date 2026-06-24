
/*
 * Level4

 1
 23
 456
 78910

 *Level 5

    *
   ***
  *****
 *******

 */

let a = 4;
let b = 1;

for(let i=0;i<a;i++){
	for(let j=0;j<=i;j++){
		process.stdout.write(b.toString());
		b++;
	}
	console.log();
}
console.log();
for(let i=0;i<a*2;i+=2){
	for(let j=0;j<=a-i/2;j++){
		process.stdout.write(" ");
	}
	for(let j=0;j<=i;j++){
		process.stdout.write("*");
	}
	console.log();
}
