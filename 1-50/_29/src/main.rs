use openssl::bn::*;
use openssl::error::ErrorStack;
use std::collections::*;

fn main() -> Result<(), ErrorStack>{

	let mut a = BigNum::new()?;
	let mut b = BigNum::new()?;

	let mut ctx = BigNumContext::new()?;

	let mut d : BTreeSet<BigNum> = BTreeSet::new();

	let mut c = BigNum::new()?;

	for i in 2..=100 {

		for k in 2..=100{

			a = BigNum::from_u32(i)?;
			b = BigNum::from_u32(k)?;

			c.exp(&a,&b,&mut ctx)?;

			d.insert(c.to_owned()?);
		}
	};

	println!("{:?}",d.len());

	Ok(())
}
