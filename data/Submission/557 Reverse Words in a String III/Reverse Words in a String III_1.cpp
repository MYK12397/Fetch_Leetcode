//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 557 Reverse Words in a String III
// https://leetcode.com//problems/reverse-words-in-a-string-iii/description/
// Fetched at 2018-07-24
// Submitted 5 months ago
// Runtime: 850 ms

class Solution {
 public:
  string reverseWords(string s) {
    string result = "";
    stack<char> temp;
    int i = 0;
    while (i < s.size()) {
      while (i < s.size() && s[i] != ' ') {
        temp.push(s[i]);
        i++;
      }

      while (!temp.empty()) {
        result = result + temp.top();
        temp.pop();
      }
      if (i < s.size()) result = result + " ";
      i++;
    }
    return result;
  }
};