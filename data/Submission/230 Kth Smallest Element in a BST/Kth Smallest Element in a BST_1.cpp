//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 230 Kth Smallest Element in a BST
// https://leetcode.com//problems/kth-smallest-element-in-a-bst/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 28 ms
// This solution defeats 1.43% cpp solutions

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
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> recur;
    recur.push(root);
    vector<TreeNode*> store;
    while (!recur.empty()) {
      if (recur.top()->left != NULL) {
        TreeNode* temp = recur.top();
        recur.push(recur.top()->left);
        temp->left = NULL;
      } else if (recur.top()->right != NULL) {
        TreeNode* temp = recur.top();
        store.push_back(recur.top());
        recur.pop();
        recur.push(temp->right);
        temp->right = NULL;
      } else {
        store.push_back(recur.top());
        recur.pop();
      }
    }
    cout << store.size() << endl;
    return store[k - 1]->val;
  }
};