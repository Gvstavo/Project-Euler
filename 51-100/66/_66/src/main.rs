use openssl::bn::BigNum;

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
	ret.remove(0);
	ret

}

#[derive(Debug)]
struct Frac {
	
	cycle: Vec<BigNum>,
	p: BigNum,
	q: BigNum,
	auxq: Vec<BigNum>,
	auxp: Vec<BigNum>,
	x: u64
}


impl Frac{

	fn new(n: u64) -> Self{

		Frac {
			cycle: sqrt_cf(n).iter().map(|x| BigNum::from_dec_str(x.to_string().as_str()).unwrap()).collect::<Vec<BigNum>>(),
			p: BigNum::from_dec_str(unsafe{(n as f64).sqrt().to_int_unchecked::<u64>().to_string().as_str()}).unwrap(),
			q: BigNum::from_u32(1).unwrap(),
			auxq: vec![BigNum::from_u32(0).unwrap(),BigNum::from_u32(1).unwrap()],
			auxp: vec![BigNum::from_u32(1).unwrap()],
			x:0
		}

	}

}

impl Iterator for  Frac {
	type Item = (BigNum,BigNum);

  fn next(&mut self) -> Option<(BigNum,BigNum)>  {
	
    	
		let len = self.cycle.len() as i64;	

    let index = (((self.x as i64) % (len))) as usize;

    self.x = self.x + 1;

		if self.x == 1{ self.auxp.push(self.p.to_owned().unwrap())}


    self.p = (self.cycle.get(index).unwrap()) * (self.auxp.get(1).unwrap());

    self.p = &self.p + (self.auxp.get(0).unwrap());

    self.q = (self.cycle.get(index).unwrap()) * (self.auxq.get(1).unwrap());

    self.q = &self.q + (self.auxq.get(0).unwrap());

    self.auxp.remove(0);

    self.auxp.push(self.p.to_owned().unwrap());

    self.auxq.remove(0);

    self.auxq.push(self.q.to_owned().unwrap());


   	Some((self.p.to_owned().unwrap(),self.q.to_owned().unwrap()))
	}

}
// // x² – Dy² = 1

fn pell_equation(d: u64) -> (BigNum,BigNum) {

	let mut solution : (BigNum,BigNum);
	let aux = BigNum::from_dec_str(d.to_string().as_str()).unwrap();
	let ret = BigNum::from_u32(1).unwrap();
	let mut f = Frac::new(d);

	loop {

		solution = f.next().unwrap();

		if &(&solution.0 * &solution.0) - &(&(&aux * &solution.1) * &solution.1) == ret {break;}

	}

	solution
	

}


fn main() {

	let mut d = 0;
	let mut x = BigNum::from_u32(0).unwrap();

	for i in 2..=1000{
		if (i as f64).sqrt().rem_euclid(1.0) == 0.0{continue;}


		if x < pell_equation(i).0{
			x = pell_equation(i).0;
			d = i;
		}
	}

	println!("{:?}", d); 




}
