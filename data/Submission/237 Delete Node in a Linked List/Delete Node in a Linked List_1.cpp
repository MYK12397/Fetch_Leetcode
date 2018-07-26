//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 237 Delete Node in a Linked List
// https://leetcode.com//problems/delete-node-in-a-linked-list/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 16 ms
// This solution defeats 1.2% cpp solutions

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  void deleteNode(ListNode* node) {
    if (node == NULL || node->next == NULL) {
      return;
    }
    node->val = node->next->val;
    ListNode* p = node->next;
    node->next = node->next->next;
    free(p);
  }
};