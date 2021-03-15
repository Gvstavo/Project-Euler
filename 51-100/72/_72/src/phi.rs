use std::cmp::min;
use std::mem::swap;
use async_std::stream::*;
use async_std::task::*;
use std::pin::*;
use std::cell::RefCell;
use std::collections::HashMap;
use futures::stream::{self, StreamExt};

pub async fn is_prime(n: i64) -> bool{

  if n == 2 { return true};
  if n % 2 == 0 {return false};
  if n == 1 {return false};
  let s = (n as f64).sqrt().ceil();

  let lim = s as i64;

  let r = (3..=lim).step_by(2);

  let mut stream = stream::iter(r);
   
  while let Some(number) = stream.next().await {
      
    if n % number == 0 { return false};
    
  }

  true

}

#[derive(Debug)]
pub struct Phi{

  pub memomy: RefCell<HashMap<u64,u64>>
}

impl Phi{
  pub fn new() -> Self {
    Phi{
      memomy: RefCell::new(HashMap::new())
    }
  }

  pub async fn next(&self, n: i64 ){

    let range = (3..n).step_by(2);

    let stream = stream::iter(range);

   // ret *= 1.0_f64 - (1.0_f64 / (*k as f64))
    
    stream.fold(1 ,|&x, acc| async move{
      if is_prime(x).await{
        acc * (1.0_f64 - (1.0_f64 / (x as f64)))
      }
      else {
        acc
      }
    
    });

  }
}

