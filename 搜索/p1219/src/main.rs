use std::io;
// use std::collections::HashSet;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut status = Status {
        // line : Vec::with_capacity(13),
        row : vec![false; 13],
        x : vec![false; 27],
        y : vec![false; 27],
        res : Vec::new(), 
        n,
    };
    let mut res = Vec::new();
    for i in 0..n {
        dfs(0, i, &mut res, &mut status);
    }

    for i in 0..usize::min(3, status.res.len()) {
        for j in 0..status.n - 1 {
            print!("{} ", status.res[i][j] + 1);
        }
        println!("{}", status.res[i][status.n - 1] + 1);
    }

    println!("{}", status.res.len());
}

struct Status {
    // line: Vec<bool>,
    row: Vec<bool>,
    x: Vec<bool>,
    y: Vec<bool>,
    res: Vec<Vec<usize>>,
    n: usize, 
}

fn check(status: &Status, i: usize, pos: usize) -> bool{
    if status.row[pos] {
        return false;
    }

    if status.x[status.n + i - pos] {
        return false;
    }

    if status.y[i + pos] {
        return false;
    }
    true
}

fn dfs(i: usize, pos: usize, res: &mut Vec<usize>, status: &mut Status) {
    if check(status, i, pos) == false {
        return;
    }

    res.push(pos);

    if i == status.n - 1 {
        let new_data = res.clone();
        status.res.push(new_data);
        res.pop();
        return;
    }   

    status.row[pos] = true;
    status.x[status.n + i - pos] = true;
    status.y[i + pos] = true;

    for j in 0..status.n {
        dfs(i + 1, j, res, status);
    }

    res.pop();
    status.row[pos] = false;
    status.x[status.n + i - pos] = false;
    status.y[i + pos] = false;
}
