//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 98 Validate Binary Search Tree
// https://leetcode.com//problems/validate-binary-search-tree/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 16 ms
// This solution defeats 2.77% cpp solutions

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
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    TreeNode* pleft = root->left;
    TreeNode* pright = root->right;
    while (pleft != nullptr && pleft->right != nullptr) {
      pleft = pleft->right;
    }
    while (pright != nullptr && pright->left != nullptr) {
      pright = pright->left;
    }
    if (pleft == nullptr) {
      if (pright == nullptr) {
        return true;
      } else
        return pright->val > root->val && isValidBST(root->right);
    } else if (pright == nullptr) {
      return pleft->val < root->val && isValidBST(root->left);
    }
    return pleft->val < root->val && pright->val > root->val &&
           isValidBST(root->left) && isValidBST(root->right);
  }
};