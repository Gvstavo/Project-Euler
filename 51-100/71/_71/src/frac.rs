use std::cmp::Ordering;

#[derive(Eq , Debug, Clone)]
pub struct Frac {
	a: i64 ,
	b: i64
}

impl Frac {
	pub fn new(numerator: i64 , denominator: i64) -> Self {
		Frac{
			a: numerator,
			b: denominator
		}
	}
}
impl Ord for Frac{
	fn cmp(&self , other: &Self) -> Ordering{

		self.a.cmp(&other.a).then(self.b.cmp(&other.b))
	}
}
impl PartialOrd for Frac {
	fn partial_cmp(&self , other: &Self) -> Option<Ordering> {
		Some(self.cmp(other))
	}
	fn lt(&self, other: &Self) -> bool {
		self.a * other.b < self.b * other.a
	}
	fn gt(&self, other: &Self) -> bool {
		self.a * other.b > self.b * other.a
	}

}
impl PartialEq for Frac{
	fn eq(&self , other: &Self) -> bool {
		self.a == other.a && self.b == other.b 
	}
}