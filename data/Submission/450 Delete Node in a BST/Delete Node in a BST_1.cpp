//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 450 Delete Node in a BST
// https://leetcode.com//problems/delete-node-in-a-bst/description/
// Fetched at 2018-07-24
// Submitted 4 months ago
// Runtime: 36 ms
// This solution defeats 1.86% cpp solutions

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
      return NULL;
    }
    if (root->val == key) {
      if (root->left != NULL) {
        TreeNode* p = root->left;
        while (p->right != NULL) {
          p = p->right;
        }
        p->right = root->right;
        root = root->left;
        return root;
      } else if (root->right != NULL) {
        TreeNode* p = root->right;
        while (p->left != NULL) {
          p = p->left;
        }
        p->left = root->left;
        root = root->right;
        return root;
      } else {
        return NULL;
      }
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
      return root;
    } else {
      root->right = deleteNode(root->right, key);
      return root;
    }
  }
};