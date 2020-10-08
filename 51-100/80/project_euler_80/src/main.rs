/*




It is well known that if the square root of a natural number is not an integer, then it is irrational. 
The decimal expansion of such square roots is infinite without any repeating pattern at all.

The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.

For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.


*/


use openssl::bn::BigNum;
use openssl::bn::BigNumContext;
use std::cmp::Ordering;


fn get_x(c: &BigNum , p: &BigNum ) -> u32{

	let mut x : u32 = 0;

	let mut auxp = BigNum::from_dec_str(p.to_dec_str().unwrap().to_string().as_str()).unwrap();
	
	let mut auxc = BigNum::from_dec_str(c.to_dec_str().unwrap().to_string().as_str()).unwrap();
	


	loop {
		
		x += 1;

		auxp.mul_word(20);
		auxp.add_word(x);

		auxp.mul_word(x);


		if auxp.ucmp(&auxc) == Ordering::Greater{
			break;
		}

		auxp = BigNum::from_dec_str(p.to_dec_str().unwrap().to_string().as_str()).unwrap();

	}

	 x -= 1;
	 x


}


fn sqrt_digits(n: u32, digits: i64) -> i64 {

	//let mut ret: Vec<i64> = Vec::new();
	let mut ret: i64 = 0;
	let int_sqrt = (n as f64).sqrt() as u32; 
	let mut c = BigNum::from_u32(n).unwrap();
	let mut x = BigNum::from_u32(0).unwrap();
	let mut y = BigNum::from_u32(int_sqrt).unwrap();
	let mut p = BigNum::from_u32(0).unwrap();
	let mut auxy = BigNum::new().unwrap();
	let mut ctx = BigNumContext::new().unwrap(); 
	let mut auxp = BigNum::new().unwrap();
	let mut auxc = BigNum::new().unwrap();

	


	p = BigNum::from_u32(int_sqrt).unwrap();

	y.mul_word(int_sqrt).unwrap();
	c.sub_word(int_sqrt * int_sqrt);


	for _ in 0..digits {

		c.mul_word(100);
		x = BigNum::from_u32(get_x(&c , &p)).unwrap();
	 	
	 	y = BigNum::from_dec_str(p.to_dec_str().unwrap().to_string().as_str()).unwrap();
	 	y.mul_word(20);

	 	auxy = BigNum::from_dec_str(p.to_dec_str().unwrap().to_string().as_str()).unwrap();
	 	auxy.mul_word(20);


	 	y.checked_add(&x , &auxy );
	 	auxy.checked_add(&y , &x );

	 	auxy.checked_mul(&x , &y, &mut ctx);

	 	y = BigNum::from_dec_str(auxy.to_dec_str().unwrap().to_string().as_str()).unwrap();
	 	
	 	ret += x.to_dec_str().unwrap().to_string().parse::<i64>().unwrap();

	 	p.mul_word(10);
	 	auxp = BigNum::from_dec_str(p.to_dec_str().unwrap().to_string().as_str()).unwrap();

	 	p.checked_add(&auxp , &x);

	 	auxc = BigNum::from_dec_str(c.to_dec_str().unwrap().to_string().as_str()).unwrap();

	 	c.checked_sub(&auxc , &y);



	}	

	 ret

} 


fn main() {


	let mut sum : i64 = 0; 

	for i in 0..100{
		
		match i{

			0|1|4|9|16|25|36|49|64|81|100 => continue,
			_ =>
				sum += ((i as f64).sqrt() as i64) + sqrt_digits(i , 99) 


		}

	}
	println!("{:?}", sum);
	  
}
