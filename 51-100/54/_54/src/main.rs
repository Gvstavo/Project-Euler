use std::fs::File;
use std::io::BufReader;
use std::io::prelude::*;
use lazy_static::lazy_static;
use regex::Regex;


#[derive(Debug)]
enum Ranking {
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

#[derive(Debug)]
enum Winner{
	Player1,
	Player2
}

#[derive(Debug)]
struct Card {
	value: String,
	suit: String
}


#[derive(Debug)]
struct Player{
	hand: Vec<Card>
	//hand: (Card , Card , Card, Card , Card)
}



fn main() {
 
	let file = File::open("p054_poker.txt").unwrap();
  let mut buf_reader = BufReader::new(file);
  let mut contents = String::new();
  buf_reader.read_to_string(&mut contents).unwrap();

  let hands : Vec<(&str, &str)> = contents.split("\n").filter_map(|x| if x.len() == 29 { Some(x.split_at(14))} else {None}).collect();


}

#[test]
fn is_royal_flush() {

	let h = Player{
		hand: vec![
			Card{value: "A".to_string(), suit: "H".to_string()},
			Card{value: "K".to_string(), suit: "H".to_string()},
			Card{value: "Q".to_string(), suit: "H".to_string()},
			Card{value: "J".to_string(), suit: "H".to_string()},
			Card{value: "10".to_string(), suit: "H".to_string()},
		]
	};

	

}