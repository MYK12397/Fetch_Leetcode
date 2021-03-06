//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 161 One Edit Distance
// https://leetcode.com//problems/one-edit-distance/description/
// Fetched at 2018-07-24
// Submitted 4 months, 4 weeks ago
// Runtime: 5 ms
// This solution defeats 4.98% cpp solutions

class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (abs(int(s.size()) - int(t.size())) > 1) {
      return false;
    }
    if (s.size() == 0 && t.size() == 0) {
      return false;
    } else if (s.size() == t.size()) {
      bool flag = true;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
          if (flag == true) {
            flag = false;
            continue;
          } else {
            return false;
          }
        }
      }
      return !flag;
    } else if (s.size() < t.size()) {
      string temp = s;
      s = t;
      t = temp;
    }
    for (int i = 0; i < t.size(); i++) {
      if (s[i] != t[i]) {
        string ss = s.substr(i + 1, s.size() - i - 1);
        string tt = t.substr(i, t.size() - i);
        return ss == tt;
      }
    }
    return true;
  }
};