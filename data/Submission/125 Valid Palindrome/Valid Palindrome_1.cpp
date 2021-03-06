//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 125 Valid Palindrome
// https://leetcode.com//problems/valid-palindrome/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 16 ms
// This solution defeats 6.25% cpp solutions

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }
    int low = 0, high = s.size() - 1;
    while (high > low) {
      while (low < s.size() && !((s[low] <= 'z' && s[low] >= 'a') ||
                                 (s[low] <= 'Z' && s[low] >= 'A') ||
                                 (s[low] >= '0' && s[low] <= '9'))) {
        low++;
      }
      while (high >= 0 && !((s[high] <= 'z' && s[high] >= 'a') ||
                            (s[high] <= 'Z' && s[high] >= 'A') ||
                            (s[high] >= '0' && s[high] <= '9'))) {
        high--;
      }
      if (low >= high) {
        return true;
      }
      if (s[low] >= '0' && s[low] <= '9') {
        if (s[high] == s[low]) {
          low++;
          high--;
        } else {
          return false;
        }
      } else if (s[high] >= '0' && s[high] <= '9') {
        return false;
      } else {
        if (toupper(s[low]) == toupper(s[high])) {
          low++;
          high--;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};