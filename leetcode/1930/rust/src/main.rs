pub fn count_palindromic_subsequence(s: String) -> i32 {
    let mut cnt = vec![0; 26];
    let mut ans = 0;
    let mut first: Vec<Option<usize>> = vec![None; 26];
    let mut last: Vec<Option<usize>> = vec![None; 26];
    let n = s.len();
    let mut prefix_cnt = vec![vec![0; 26]; n];
    for i in 0..n {
        let ii = s.as_bytes()[i] as usize - 'a' as usize;
        cnt[ii] += 1;
        prefix_cnt[i] = cnt.clone();
        if first[ii].is_none() {
            first[ii] = Some(i);
        }
        last[ii] = Some(i);
    }
    for i in 0..26 {
        if let Some(f) = first[i] {
            if let Some(l) = last[i] {
                if l - f >= 2 {
                    let pa = &prefix_cnt[f];
                    let pb = &prefix_cnt[l - 1];
                    for i in 0..26 {
                        if pb[i] > pa[i] {
                            ans += 1;
                        }
                    }
                }
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(count_palindromic_subsequence("aabca".to_string()), 3);
    assert_eq!(count_palindromic_subsequence("adc".to_string()), 0);
    assert_eq!(count_palindromic_subsequence("bbcbaba".to_string()), 4);
}
