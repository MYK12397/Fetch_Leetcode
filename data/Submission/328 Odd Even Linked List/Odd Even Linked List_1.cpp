//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 328 Odd Even Linked List
// https://leetcode.com//problems/odd-even-linked-list/description/
// Fetched at 2018-07-24
// Submitted 2 years, 2 months ago
// Runtime: 20 ms
// This solution defeats 4.36% cpp solutions

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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode *odd = head, *even = head->next;
    if (even == nullptr) return head;
    ListNode* newhead = even;
    while (even != nullptr && odd != nullptr) {
      odd->next = even->next;
      if (odd->next != nullptr) {
        odd = odd->next;
      } else {
        odd->next = newhead;
        return head;
      }
      even->next = odd->next;
      even = even->next;
    }
    odd->next = newhead;
    return head;
  }
};