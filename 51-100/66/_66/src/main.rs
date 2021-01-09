fn sqrt_cf(d: u64) -> Vec<u64>{

	let r = unsafe {(d as f64).sqrt().floor().to_int_unchecked::<u64>()};

	let mut ret : Vec<u64> = Vec::new(); 

	if r*r == d {return ret};

	ret.push(r);

	let mut a : u64 = r;
	let mut p : u64 = 0;
	let mut q : u64 = 1;

	loop{

		p = a*q - p;
		q = ((d - p*p)/q) as u64;
		a = ((r + p)/q) as u64;
		ret.push(a);

		if q == 1{
			break;
		}
	}
	ret

}

#[derive(Debug)]
struct Frac {
	
	cycle: Vec<u64>,
	p: u64,
	q: u64,
	auxq: Vec<u64>,
	auxp: Vec<u64>,
	x: u64
}


impl Frac{

	fn new(n: u64) -> Self{

		Frac {
			cycle: sqrt_cf(n),
			p: unsafe{(n as f64).sqrt().to_int_unchecked::<u64>()},
			q: 1,
			auxq: vec![0,1],
			auxp: vec![1],
			x:0
		}

	}

}

impl Iterator for Frac {
    type Item = (u64,u64);

    fn next(&mut self) -> Option<(u64,u64)>  {
	
	    self.x = self.x + 1;
    	
    	let len = self.cycle.len() as i64;	

    	let index = (((self.x as i64) % (len -1))) as usize;
    	if self.x == 1{ self.auxp.push(self.p)}

    	self.p = (*self.cycle.get(index+1).unwrap()) * (*self.auxp.get(1).unwrap()) + (*self.auxp.get(0).unwrap());

    	self.q = (*self.cycle.get(index+1).unwrap()) * (*self.auxq.get(1).unwrap()) + (*self.auxq.get(0).unwrap());

    	self.auxp.remove(0);

    	self.auxp.push(self.p);

    	self.auxq.remove(0);

    	self.auxq.push(self.q);


    	Some((self.p,self.q))

    }

   
}
fn main() {
	let mut f = Frac::new(2);

		

}
