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
 
 *Level2
1
22
333
4444

* loop3
1
12
123
1234

 */

fn main() {
    let a = 4;
    for i in 0..a {
        for _j in 0..a-i {
            print!("*");
        }
        println!();
    }
    println!();
    for i in 0..a {
        for _j in 0..=i {
            print!("{}",i+1);
        }
        println!();
    }

    println!();
    for i in 0..a {
        for j in 0..=i {
            print!("{}",j+1);
        }
        println!();
    }

}
