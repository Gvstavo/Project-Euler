mod frac;
use frac::Frac;
fn main() {

	let mut  v : Vec<Frac> = vec![ Frac::new(1,2), Frac::new(4,7), Frac::new(7,8), Frac::new(4,5), Frac::new(1,6), Frac::new(5,6), Frac::new(1,7), Frac::new(5,7), Frac::new(1,8), Frac::new(2,3), Frac::new(3,7), Frac::new(1,4), Frac::new(2,5), Frac::new(6,7), Frac::new(1,5), Frac::new(1,3), Frac::new(3,4), Frac::new(5,8), Frac::new(3,5), Frac::new(3,8), Frac::new(2,7)];
	v.sort();
	
}
