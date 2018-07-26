//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 148 Sort List
// https://leetcode.com//problems/sort-list/description/
// Fetched at 2018-07-24
// Submitted 2 years, 2 months ago
// Runtime: 92 ms
// This solution defeats 14.07% cpp solutions

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
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *a = head, *b = head->next;
    ListNode *front = a, *back = b;
    while (back != nullptr) {
      front->next = back->next;
      front = front->next;
      if (front == nullptr) {
        break;
      }
      back->next = front->next;
      back = back->next;
    }
    ListNode* p = sortList(a);
    ListNode* q = sortList(b);
    head = nullptr;
    ListNode* tail = nullptr;
    ListNode *tempp = p, *tempq = q;
    while (p != nullptr && q != nullptr) {
      tempp = p->next;
      tempq = q->next;
      if (p->val < q->val) {
        if (head == nullptr) {
          head = p;
          head->next = nullptr;
          tail = head;
        } else {
          tail->next = p;
          p->next = nullptr;
          tail = p;
        }
        p = tempp;
      } else {
        if (head == nullptr) {
          head = q;
          head->next = nullptr;
          tail = head;
        } else {
          tail->next = q;
          q->next = nullptr;
          tail = q;
        }
        q = tempq;
      }
    }
    if (p == nullptr && q != nullptr) {
      tail->next = q;
    }
    if (q == nullptr && p != nullptr) {
      tail->next = p;
    }
    return head;
  }
};