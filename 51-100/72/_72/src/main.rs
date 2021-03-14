mod phi;
use phi::Phi;
use async_std::prelude::*;
use futures::stream::{self, StreamExt};
#[async_std::main]
async fn main() {

	let  p = Phi::new();

	let mut stream = stream::iter(1..12000);

	let mut  s :u64 = 0;
  while let Some(number) = stream.next().await {
  	
  	p.next().await;   

  	s += *p.phi.borrow();
  	
  }
}
