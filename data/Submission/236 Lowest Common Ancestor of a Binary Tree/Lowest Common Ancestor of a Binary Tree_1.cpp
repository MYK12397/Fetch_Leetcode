//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 236 Lowest Common Ancestor of a Binary Tree
// https://leetcode.com//problems/lowest-common-ancestor-of-a-binary-tree/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 24 ms
// This solution defeats 8.53% cpp solutions

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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p == NULL) {
      return q;
    }
    if (q == NULL) {
      return p;
    }
    if (root == NULL) {
      return NULL;
    }
    if (p == root || q == root) {
      return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL) {
      return root;
    } else if (left == NULL) {
      return right;
    } else
      return left;
  }
};