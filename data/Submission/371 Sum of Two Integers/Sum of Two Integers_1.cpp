//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 371 Sum of Two Integers
// https://leetcode.com//problems/sum-of-two-integers/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  int getSum(int a, int b) {
    while (b) {
      int c = a ^ b;
      int d = (a & b) << 1;
      a = c;
      b = d;
    }
    return a;
  }
};