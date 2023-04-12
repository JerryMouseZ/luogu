use std::io;
fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let mut i = 0;
    let mut t: Vec<(i32, i32)> = input.split_whitespace().map(|x| {
        i += 1;
        (x.parse().unwrap(), i)
    }).collect();
    t.sort_by(|x, y| {
        x.0.cmp(&y.0)
    });
    let mut sum: i64 = 0;
    for j in 0..t.len() - 1 {
        print!("{} ", t[j].1);
        sum += (t[j].0 * (n - j as i32 - 1)) as i64;
    }
    println!("{}", t[t.len() - 1].1);
    println!("{:.2}", sum as f64 / n as f64);
}
