use std::fs::File;
use std::io::BufReader;
use std::io::prelude::*;
#[derive(Debug)]
enum Hand {
	RoyalFlush,
	StraightFlush,
	FourKind,
	FullHouse,
	Flush,
	Straight,
	ThreeKind,
	TwoPair,
	Pair,
	HighCard
}

fn main() {
 
	let file = File::open("p054_poker.txt").unwrap();
  let mut buf_reader = BufReader::new(file);
  let mut contents = String::new();
  buf_reader.read_to_string(&mut contents).unwrap();

  let hands : Vec<(&str, &str)> = contents.split("\n").map(|x| x.split_at(14)).collect();

  println!("{:?}", hands);

}
