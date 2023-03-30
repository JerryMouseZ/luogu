use std::io;
fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let args: Vec<usize> = input.split_whitespace().map(|s| {
        s.parse().unwrap()
    }).collect();

    let (n, m, p) = (args[0], args[1], args[2]);
    let mut collections: Vec<usize> = (0..n + 1).collect();
    for _i in 0..m {
        let mut input: String = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let line: Vec<usize> = input.split_whitespace().map(|s| s.parse().unwrap()).collect();
        let (x, y) = (line[0], line[1]);
        union(&mut collections, x, y);
    }

    for _i in 0..p {
        let mut input: String = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let line: Vec<usize> = input.split_whitespace().map(|s| s.parse().unwrap()).collect();
        let (x, y) = (line[0], line[1]);
        if find(&mut collections, x) == find(&mut collections, y) {
            println!("Yes");
        } else {
            println!("No");
        }
    }
}

fn find(collections: &mut Vec<usize>, x: usize) -> usize {
    if collections[x] != x {
        collections[x] = find(collections, collections[x]);
    }
    return collections[x];
}

fn union(collections: &mut Vec<usize>, x: usize, y: usize) {
    let (a, b) = (find(collections, x), find(collections, y));
    if a < b {
        collections[b] = a;
    } else {
        collections[a] = b;
    }
}
