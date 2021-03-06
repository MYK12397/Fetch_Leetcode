//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 24 Swap Nodes in Pairs
// https://leetcode.com//problems/swap-nodes-in-pairs/description/
// Fetched at 2018-07-24
// Submitted 5 months, 1 week ago
// Runtime: 5 ms
// This solution defeats 0.05% cpp solutions

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
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    ListNode *p1 = head;
    ListNode *p2 = head->next;
    if (p2 == NULL) {
      return p1;
    }
    ListNode *t = swapPairs(p2->next);
    p2->next = p1;
    p1->next = t;
    return p2;
  }
};