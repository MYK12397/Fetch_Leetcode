//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 94 Binary Tree Inorder Traversal
// https://leetcode.com//problems/binary-tree-inorder-traversal/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

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
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return vector<int>();
    }
    stack<TreeNode*> Q;
    TreeNode* p = root;
    vector<int> mid_visit;
    while (!Q.empty() || p != nullptr) {
      while (p != nullptr) {
        Q.push(p);
        p = p->left;
      }
      if (!Q.empty()) {
        p = Q.top();
        Q.pop();
        mid_visit.push_back(p->val);
        p = p->right;
      }
    }
    return mid_visit;
  }
};