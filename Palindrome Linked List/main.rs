pub enum address {
    address(Box<ListNode>),
    Nil,
}

pub struct ListNode 
{
	pub val: i32,
	pub next: address,
}

impl ListNode 
{
	#[inline]
	fn new(val: i32) -> Self 
	{
		ListNode 
		{
		  next: address::Nil,
		  val
		}
	}
	fn append(&mut self, elem: i32) {
        match self.next {
            address::address(ref mut next_address) => {
                next_address.append(elem);
            }
            address::Nil => {
                let node = ListNode {
                    val: elem,
                    next: address::Nil,
                };
                self.next = address::address(Box::new(node))
            }
        }
	}
}

fn main()
{
	let mut _head = ListNode::new(1);
	_head.append(2);
	println!("{}", _head.val);
}