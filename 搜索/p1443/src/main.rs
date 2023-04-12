use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let args: Vec<usize> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let (n, a, b) = (args[0], args[1], args[2]);

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let steps: Vec<usize> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();

    let mut access = vec![false; n];
    access[a - 1] = true;

    let mut sum = i32::max_value();
    dfs(n, a - 1, b - 1, &steps, &mut access, 0, &mut sum);
    if sum == i32::max_value() {
        println!("-1");
        return;
    }
    println!("{}", sum);
}

fn dfs(n: usize, cur: usize, target: usize, steps: &[usize], access: &mut [bool], k: i32, sum: &mut i32) {
    if cur == target {
        *sum = k.min(*sum);
        return;
    }
    if k >= *sum {
        return;
    }

    access[cur] = true;
    if cur >= steps[cur] && !access[cur - steps[cur]] {
        dfs(n, cur - steps[cur], target, steps, access, k + 1, sum);
    }

    if cur + steps[cur] < n && !access[cur + steps[cur]] {
        dfs(n, cur + steps[cur], target, steps, access, k + 1, sum);
    }
    access[cur] = false;
}