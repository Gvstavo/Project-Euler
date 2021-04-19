mod frac;
use frac::Frac;

/*

    (a, b, c, d) = (0, 1, 1, n)
    if descending:
        (a, c) = (1, n - 1)
    print("{0}/{1}".format(a, b))
    while (c <= n and not descending) or (a > 0 and descending):
        k = (n + b) // d
        (a, b, c, d) = (c, d, k * c - a, k * d - b)
        print("{0}/{1}".format(a, b))

*/

fn _farey(n: i64) -> (i64, i64) {

	let  (mut a,mut  b, mut c, mut d) = (0, 1, 1, n);

	let mut aux =  (0, 1, 1, n);
	let mut count = 0;
	let mut k = 0;	
	let mut prev  = (a,b);
	while c <= n {

		k = (n + b).div_euclid(d);
		count  += 1;
		println!("{:?}",count );
		aux = (c, d, k * c - a, k * d - b);

		prev = (a,b);


		a = aux.0;
		b = aux.1;
		c = aux.2;
		d = aux.3;
		
		if (a,b) == (3,7){
			break
		}	
	}
	prev

}


fn main() {
	
	let ret = _farey(1_000_000);	

	println!("{:?}",ret );
}
