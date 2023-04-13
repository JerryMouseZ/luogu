use std::collections::BinaryHeap;
use std::cmp::Reverse;
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let _n: i32 = input.trim().parse().unwrap();

    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut heap: BinaryHeap<Reverse<i32>> = input.split_whitespace().map(|x| Reverse(x.parse().unwrap())).collect();
    let mut ans = 0;
    while heap.len() > 1 {
        let Reverse(x) = heap.pop().unwrap();
        let Reverse(y) = heap.pop().unwrap();
        ans += x + y;
        heap.push(Reverse(x + y));
    }
    println!("{}", ans);
}
