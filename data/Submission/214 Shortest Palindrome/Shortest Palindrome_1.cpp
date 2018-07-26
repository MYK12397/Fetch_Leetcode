//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 214 Shortest Palindrome
// https://leetcode.com//problems/shortest-palindrome/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 3 ms
// This solution defeats 97.21% cpp solutions

class Solution {
 public:
  bool is_palindrome(string& s, int start, int end) {
    end--;
    while (start < end) {
      if (s[start++] != s[end--]) {
        return false;
      }
    }
    return true;
  }
  string shortestPalindrome(string s) {
    if (s.empty()) {
      return s;
    }
    int j = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == s[j]) {
        j += 1;
      }
    }
    if (j == s.size()) {
      return s;
    }
    string suffix = s.substr(j);
    string temp = suffix;
    reverse(temp.begin(), temp.end());
    return temp + shortestPalindrome(s.substr(0, j)) + suffix;
  }
};