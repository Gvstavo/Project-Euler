fn count_sb(n: i64) -> i64{

	let limit =n;

	let mut count : i64 = 0;
	let mut top : i64 = 0;
	let mut stack : Vec<i64> = vec![0; limit.div_euclid(2) as usize];

	// stack.reserve(limit.div_euclid(2) as usize);

	let mut left : i64= 3;

	let mut right : i64= 2;

	loop {
		
		let med = left + right;
		if med > limit {
			if top > 0{
				left = right;
				top = top -1;
				right = stack[top as usize];
			}
			else{
				break;
			}
		}
		else{
			count += 1;
			stack[top as usize] = right;
			top +=1;
			right = med;
		}
	}

	count


}


fn main() {
	
	let ret = count_sb(1_000_000);

	println!("{:?}", ret);

}
