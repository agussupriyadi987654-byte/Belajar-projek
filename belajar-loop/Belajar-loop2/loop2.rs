
/*
 * Level1

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
fn main() {
    let a: u8 = 4;
    let mut b: u8 = 1;
    for i in 0..a {
        for _j in 0..=i {
            print!("{}",b);
            b+=1;
        }
        println!();
    }
    println!();
    for i in (0..a*2).step_by(2) {
        for _j in 0..a-i/2 {
            print!(" ");
        }
        for _j in 0..=i {
            print!("*");
        }
        println!();
    }
}
