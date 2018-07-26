// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 653 Two Sum IV - Input is a BST
// https://leetcode.com//problems/two-sum-iv---input-is-a-bst/description/
// Fetched at 2018-07-24
// Submitted 1 month, 4 weeks ago
// Runtime: 28 ms
// This solution defeats 6.3% java solutions

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
  public TreeNode isIn(TreeNode root, int k) {
    TreeNode p = root;
    while (p != null) {
      if (p.val == k) {
        return p;
      } else if (p.val < k) {
        p = p.right;
      } else {
        p = p.left;
      }
    }
    return null;
  }

  public boolean isIn(TreeNode root, TreeNode p, int k) {
    if (p == null) {
      return false;
    }
    TreeNode q = isIn(root, k - p.val);
    if (q != null && q != p) {
      return true;
    }
    return isIn(root, p.left, k) || isIn(root, p.right, k);
  }

  public boolean findTarget(TreeNode root, int k) {
    return isIn(root, root, k);
  }
}