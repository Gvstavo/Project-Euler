fn phi_1_to_n(n: i64) -> i64{

	let mut phi : Vec<i64> = (0..=n).collect();

	for i in 2..=n{

		if phi[i as usize] == i {
			for j in (i..=n).step_by(i as usize)  {
				phi[j as usize] -= phi[j as usize].checked_div(i).unwrap();
			}
		}
	};

	phi.iter().sum::<i64>() - 1

}

fn main() {


	println!("{}",phi_1_to_n(1_000_000));


}

