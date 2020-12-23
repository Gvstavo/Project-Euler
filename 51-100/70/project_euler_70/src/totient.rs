use std::collections::HashMap;
use std::cell::RefCell;

fn is_prime(n: i64) -> bool{

	if n == 2 { return true};
	if n % 2 == 0 {return false}
	let s = (n as f64).sqrt().ceil();

	let lim = s as i64;

	for i in (3..=lim).step_by(2){



		if n % i == 0 { return false};

	}
	true

}

#[derive(Debug)]
pub struct Totient{

	value: HashMap<i64,i64>,
	primes: HashMap<i64,i64>,
	last: RefCell<i64>
}


impl Totient{

	fn phi(&self, n: i64) -> i64 {

		
	 	let mut ret = 1.0_f64;

	 	for (k,v) in &self.primes {	
	 		
	 		if *k > n.div_euclid(2){break;}; 

	 		if  *v == 1 && n % k == 0 {ret *= 1.0_f64 - (1.0_f64 / (*k as f64))}

	 	};

	 	// for i in &self.primes {

	 	// 	if n % i == 0 {ret *= 1.0_f64 - (1.0_f64 / (*i as f64))}

	 	// };

	 	((n as f64) * ret) as i64
	 }

	pub fn new() -> Self{

		Totient{

			value: HashMap::new(),
			primes: HashMap::new(),
			last: RefCell::new(1)
		}

	}

	pub fn next(&mut self){

		let mut counter = self.last.borrow_mut();

    *counter = *counter + 1;	

 		match is_prime(*counter){
 			false => {
				self.value.insert(*counter, self.phi(*counter));
				()

 			}
 			_ =>{

			self.primes.insert(*counter, *counter-1);
			()
 			}
 		}

	}

	pub fn get_value(&self) -> HashMap<i64,i64>{

		self.value.clone()

	}
	// pub fn print(&self){

	// 	println!("{:?}",self.last.clone().into_inner() );
	//  }

 }