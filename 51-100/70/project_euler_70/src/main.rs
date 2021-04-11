mod totient;
use totient::*;
use std::collections::HashMap;


fn phi_1_to_n(n: i64) -> Vec<i64>{

	let mut phi : Vec<i64> = (0..=n).collect();


	for i in 2..=n{

		if phi[i as usize] == i {
			for j in (i..=n).step_by(i as usize)  {
				phi[j as usize] -= phi[j as usize].checked_div(i).unwrap();
			}
		}
	};
	phi

}


fn main() {

	let ret = phi_1_to_n(10_000_000);

	let kkk = |x: &(usize,&i64)| {

    let  mut digits : Vec<i64> = (0..=9).map(|x| 0).collect();

    let mut aux1= x.0 as i64;

    let mut aux2 = *x.1;

    while aux1 != 0{
    	let mut elem = digits.get_mut((aux1 % 10) as usize).unwrap();
    	*elem += 1;
    	aux1 = aux1.div_euclid(10);
    };

    while aux2 != 0{
     	let mut elem = digits.get_mut((aux2 % 10) as usize).unwrap();
    	*elem -= 1;
    	aux2 = aux2.div_euclid(10);
    };


    if digits.iter().find(|x| **x != 0).is_none() &&  *x.1 > 0 && x.0 as i64 != *x.1 {
    	Some((x.0, x.0 as f64 / *x.1 as f64))
    }
    else{
    	None
    }

	print!("{:?}", ret.iter().enumerate().collect::<Vec<(usize,&i64)>>().iter().filter_map(|x| kkk(x)).collect::<Vec<(usize,f64)>>().iter().min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()));


}
