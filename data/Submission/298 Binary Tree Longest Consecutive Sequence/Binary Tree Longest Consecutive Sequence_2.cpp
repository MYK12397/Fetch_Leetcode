//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 298 Binary Tree Longest Consecutive Sequence
// https://leetcode.com//problems/binary-tree-longest-consecutive-sequence/description/
// Fetched at 2018-07-24
// Submitted 4 months, 3 weeks ago
// Runtime: 26 ms
// This solution defeats 7.92% cpp solutions

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int helper(TreeNode* root, int& ret) {
    if (root == NULL) {
      return 0;
    }
    int v = 1;
    if (root->left != NULL && root->val == root->left->val - 1) {
      v = max(v, 1 + helper(root->left, ret));

    } else {
      helper(root->left, ret);
    }
    if (root->right != NULL && root->val == root->right->val - 1) {
      v = max(v, 1 + helper(root->right, ret));
    } else {
      helper(root->right, ret);
    }

    ret = max(ret, v);
    return v;
  }
  int longestConsecutive(TreeNode* root) {
    int ret = 0;
    helper(root, ret);
    return ret;
  }
};