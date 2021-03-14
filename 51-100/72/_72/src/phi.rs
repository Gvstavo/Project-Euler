use std::cmp::min;
use std::mem::swap;
use async_std::stream::*;
use async_std::task::*;
use std::pin::*;
use std::cell::RefCell;
use futures::stream::{self, StreamExt};

fn gcd(mut u: u64, mut v: u64) -> u64 {

  if u == 0 {
    return v;
  } else if v == 0 {
    return u;
  }
  let i = u.trailing_zeros();  
  u >>= i;
  let j = v.trailing_zeros();  
  v >>= j;
  let k = min(i, j);

  loop {

    if u > v {
      swap(&mut u, &mut v);
    }

    v -= u;
    if v == 0 {
      return u << k;
    }

    v >>= v.trailing_zeros();
  }
}
#[derive(Debug)]
pub struct Phi{

  pub n: RefCell<u64>,
  pub phi: RefCell<u64>
}

impl Phi{
  pub fn new() -> Self {
    Phi{
      n: RefCell::new(1),
      phi: RefCell::new(1)
    }
  }

   pub async fn next(&self){
    let mut c = self.n.borrow_mut();

    let mut count : u64 = 0;

    *c = *c + 1;
    
    let mut stream = stream::iter(1..*c);

    while let Some(number) = stream.next().await {
      
      if gcd(*c,number) == 1 {count+=1;}
    
    }

    let mut p = self.phi.borrow_mut();

    *p = count;
  }
}


// impl Stream for Phi {
//     type Item = u64;

//     async fn poll_next(mut self: Pin<&mut Self>, cx: &mut Context<'_>) -> Poll<Option<Self::Item>> {
      
//       self.n += 1;
      
//       Poll::Ready(Some(self.n))

//     }
// }