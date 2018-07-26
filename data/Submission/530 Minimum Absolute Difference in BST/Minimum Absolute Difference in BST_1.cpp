//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 530 Minimum Absolute Difference in BST
// https://leetcode.com//problems/minimum-absolute-difference-in-bst/description/
// Fetched at 2018-07-24
// Submitted 1 year, 1 month ago
// Runtime: 29 ms
// This solution defeats 4.78% cpp solutions

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
  vector<int> left_visit(TreeNode* root) {
    if (root == NULL) {
      return vector<int>();
    } else {
      vector<int> left = left_visit(root->left);
      vector<int> right = left_visit(root->right);
      left.push_back(root->val);
      right.insert(right.begin(), left.begin(), left.end());
      return right;
    }
  }
  int getMinimumDifference(TreeNode* root) {
    vector<int> nums = left_visit(root);
    int ret = pow(2, 32) - 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (abs(nums[i + 1] - nums[i]) < ret) {
        ret = abs(nums[i + 1] - nums[i]);
      }
    }
    return ret;
  }
};