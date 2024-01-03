pub fn ways_to_split_array(nums: Vec<i32>) -> i32 {
    let sum: i64 = nums.iter().map(|x| *x as i64).sum();
    let mut left = 0i64;
    let mut ans = 0;
    for i in 0..nums.len() - 1 {
        left += nums[i] as i64;
        if left >= sum - left {
            ans += 1;
        }
    }
    ans
}

fn main() {
    assert_eq!(ways_to_split_array(vec![10, 4, -8, 7]), 2);
    assert_eq!(ways_to_split_array(vec![2, 3, 1, 0]), 2);
}
