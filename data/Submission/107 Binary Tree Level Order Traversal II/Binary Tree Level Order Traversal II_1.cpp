//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 107 Binary Tree Level Order Traversal II
// https://leetcode.com//problems/binary-tree-level-order-traversal-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 172 ms

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
  vector<vector<int>> levelOrderTop(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return {{root->val}};
    }
    vector<vector<int>> left_order = levelOrderTop(root->left);
    vector<vector<int>> right_order = levelOrderTop(root->right);
    left_order.resize(max(left_order.size(), right_order.size()));
    for (int i = 0; i < right_order.size(); i++) {
      for (int j = 0; j < right_order[i].size(); j++) {
        left_order[i].push_back(right_order[i][j]);
      }
    }
    vector<int> temp = {root->val};
    left_order.insert(left_order.begin(), temp);
    return left_order;
  }
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result = levelOrderTop(root);
    reverse(result.begin(), result.end());
    return result;
  }
};