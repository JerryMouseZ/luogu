use std::io;
fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    let mut contests: Vec<(i32, i32)> = Vec::new();
    for _i in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let contest: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
        contests.push((contest[0], contest[1]));
    }
    
    contests.sort_by_key(|x| x.0);
    let mut ans = 0;
    let mut end = 0;
    contests.iter().for_each(|x| {
        if x.0 >= end {
            ans += 1;
            end = x.1;
        } else if x.1 < end {
            end = x.1;
        }
    });
    println!("{}", ans);
}
