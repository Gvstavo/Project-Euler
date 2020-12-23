mod totient;
use totient::*;

fn main() {

	let mut n = Totient::new();
  
  let mut ret : i64 = 0;	
  let mut aux : f64 = 0.0_f64;

   for _ in (2..1000000){

   	n.next();

  }

  println!("{:?}",n.get_value().get(&510510));
  // for (key,value) in n.get_value().iter(){

  // 	if ((key / value) as f64) > aux{
  // 		aux = (key / value) as f64;
  // 		ret = *key;
  // 	}

  // }

  // print!("{:?}",ret );

}
