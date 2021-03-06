//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 95 Unique Binary Search Trees II
// https://leetcode.com//problems/unique-binary-search-trees-ii/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 33 ms

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
  vector<TreeNode*> helper(vector<int>& nums) {
    int n = nums.size();
    vector<TreeNode*> result;
    if (n == 0) {
      return result;
    }
    if (n == 1) {
      TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
      root->val = nums[0];
      root->left = nullptr;
      root->right = nullptr;
      result.push_back(root);
      return result;
    }
    for (int i = 0; i < nums.size(); i++) {
      vector<int> l(i);
      vector<int> r(n - i - 1);
      copy(nums.begin(), nums.begin() + i, l.begin());
      copy(nums.begin() + i + 1, nums.end(), r.begin());
      vector<TreeNode*> lr = helper(l);
      vector<TreeNode*> rr = helper(r);
      if (lr.empty()) {
        for (int j = 0; j < rr.size(); j++) {
          TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
          root->val = nums[i];
          root->left = nullptr;
          root->right = rr[j];
          result.push_back(root);
        }
      } else if (rr.empty()) {
        for (int j = 0; j < lr.size(); j++) {
          TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
          root->val = nums[i];
          root->left = lr[j];
          root->right = nullptr;
          result.push_back(root);
        }
      } else {
        for (int j = 0; j < lr.size(); j++) {
          for (int k = 0; k < rr.size(); k++) {
            TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
            root->val = nums[i];
            root->left = lr[j];
            root->right = rr[k];
            result.push_back(root);
          }
        }
      }
    }
    return result;
  }
  vector<TreeNode*> generateTrees(int n) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
      nums.push_back(i);
    }
    return helper(nums);
  }
};