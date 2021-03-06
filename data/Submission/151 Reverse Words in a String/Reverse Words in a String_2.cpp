//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 151 Reverse Words in a String
// https://leetcode.com//problems/reverse-words-in-a-string/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 21 ms
// This solution defeats 2.22% cpp solutions

class Solution {
 public:
  void reverseWords(string &s) {
    if (s.empty()) {
      return;
    }
    stack<string> Q;
    int i = 0, space = 0;
    while (s[i] == ' ') {
      i++;
    }
    while (i < s.size()) {
      space = i;
      while (space < s.size() && s[space] != ' ') {
        space++;
      }
      Q.push(s.substr(i, space - i));
      i = space;
      while (i < s.size() && s[i] == ' ') {
        i++;
      }
    }
    s.clear();
    while (!Q.empty()) {
      s = s + Q.top();
      s = s + " ";
      Q.pop();
    }
    if (s[s.size() - 1] == ' ') {
      s.erase(s.end() - 1);
    }
  }
};