// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 725 Split Linked List in Parts
// https://leetcode.com//problems/split-linked-list-in-parts/description/
// Fetched at 2018-07-24
// Submitted 1 month, 4 weeks ago
// Runtime: 4 ms
// This solution defeats 6.21% java solutions

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution {
  public ListNode[] splitListToParts(ListNode root, int k) {
    int n = 0;
    ListNode p = root;
    while (p != null) {
      n++;
      p = p.next;
    }
    int base = n / k, mod = n - base * k;

    ListNode[] ret = new ListNode[k];

    ListNode q = root;
    int i = 0;
    for (; i < mod; i++) {
      p = q;
      ret[i] = p;
      for (int j = 0; j < base; j++) {
        p = p.next;
      }
      q = p.next;
      p.next = null;
    }
    for (; i < k; i++) {
      p = q;
      ret[i] = p;
      for (int j = 0; j < base - 1; j++) {
        p = p.next;
      }
      if (p != null) {
        q = p.next;
        p.next = null;
      }
    }
    return ret;
  }
}
