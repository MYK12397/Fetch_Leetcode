//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 476 Number Complement
// https://leetcode.com//problems/number-complement/description/
// Fetched at 2018-07-24
// Submitted 4 months, 1 week ago
// Runtime: 6 ms

class Solution {
 public:
  int findComplement(int num) {
    long long int i = 1;
    while (i <= num) {
      i *= 2;
    }
    return i - 1 - num;
  }
};