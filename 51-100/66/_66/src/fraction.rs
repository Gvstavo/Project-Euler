// fn sqrt_cf(d: u64) -> Vec<u64>{

// 	let r = unsafe {(d as f64).sqrt().floor().to_int_unchecked::<u64>()};

// 	let mut ret : Vec<u64> = Vec::new(); 

// 	if r*r == d {return ret};

// 	ret.push(r);

// 	let mut a : u64 = r;
// 	let mut p : u64 = 0;
// 	let mut q : u64 = 1;

// 	loop{

// 		p = a*q - p;
// 		q = ((d - p*p)/q) as u64;
// 		a = ((r + p)/q) as u64;
// 		ret.push(a);

// 		if q == 1{
// 			break;
// 		}
// 	}
// 	ret

// }

// #[derive(Debug)]
// pub struct Frac {
	
// 	cycle: Vec<u64>,
// 	p: u64,
// 	q: u64,
// 	vecq: Vec<u64>,
// 	vecp: Vec<u64>,
// 	x: u64
// }


// impl Frac{

// 	pub fn new(n: u64) -> Self{

// 		Frac {
// 			cycle: sqrt_cf(n),
// 			p: unsafe{(n as f64).sqrt().to_int_unchecked::<u64>()},
// 			q: 1,
// 			auxq: vec![0,1],
// 			auxp: vec![1],
// 			x:0
// 		}

// 	}

// }

// impl Iterator for Frac {
//     type Item = u64;

//     fn next(&mut self)  {
//     	self.x = self.x + 1;
//     	()
//     }
// }


