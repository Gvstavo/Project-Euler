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


fn main() {

	let ret = (2..=10000).collect::<Vec<u64>>().iter().map(|x| sqrt_cf(*x).len() as u64).filter(|x| *x > 0 && (*x - 1) % 2 > 0).fold(0, |acc, _x| acc + 1);

	println!("{:?}",ret);

	


}
