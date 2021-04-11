mod frac;
use frac::Frac;

fn phi_1_to_n(n: i64) -> (){

	let mut phi : Vec<i64> = (0..=n).collect();

	let mut ret : Vec<Frac> = Vec::new();

	for i in 2..=n{

		if phi[i as usize] == i {
			for j in (i..=n).step_by(i as usize)  {
				phi[j as usize] -= phi[j as usize].checked_div(i).unwrap();
			}
		}
	};


}


fn main() {

	print!("{:?}", phi_1_to_n(8));

}
