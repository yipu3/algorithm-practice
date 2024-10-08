// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;
pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
        match root {
            Some(root) => {
                let root = root.borrow();
                dfs(root.left.clone(), v);
                dfs(root.right.clone(), v);
                v.push(root.val);
            }
            None => (),
        }
    }
    let mut v = Vec::new();
    dfs(root, &mut v);
    v
}

fn main() {
    assert_eq!(
        postorder_traversal(Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: None,
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None,
                }))),
                right: None,
            }))),
        })))),
        vec![3, 2, 1]
    );
}
