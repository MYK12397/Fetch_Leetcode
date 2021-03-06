//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 109 Convert Sorted List to Binary Search Tree
// https://leetcode.com//problems/convert-sorted-list-to-binary-search-tree/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 28 ms
// This solution defeats 5.1% cpp solutions

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
      p->val = head->val;
      p->left = nullptr;
      p->right = nullptr;
      return p;
    }
    int size = 0;
    ListNode* p = head;
    while (p != nullptr) {
      p = p->next;
      size++;
    }
    p = head;
    int i = 0;
    while (i < size / 2 - 1) {
      p = p->next;
      i++;
    }
    ListNode* q = p->next;
    p->next = nullptr;
    ListNode* back = q->next;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = q->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(back);
    return root;
  }
};