fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let nx: Vec<i64> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let x = nx[1];
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut a: Vec<i64> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut ans: i64 = 0;
    if a[0] > x {
        ans += a[0] - x;
        a[0] = x;
    }

    for i in 0..a.len() - 1 {
        if a[i] + a[i + 1] > x {
            ans += a[i] + a[i + 1] - x;
            a[i + 1] -= a[i] + a[i + 1] - x;
        }
    }
    println!("{}", ans);
}
