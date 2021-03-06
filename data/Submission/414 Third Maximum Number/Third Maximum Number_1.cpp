//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 414 Third Maximum Number
// https://leetcode.com//problems/third-maximum-number/description/
// Fetched at 2018-07-24
// Submitted 4 months, 1 week ago
// Runtime: 9 ms
// This solution defeats 3.01% cpp solutions

class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int ret = INT_MIN;
    for (auto a : nums) {
      max1 = max(max1, a);
    }
    for (auto a : nums) {
      if (a == max1) {
        continue;
      }
      max2 = max(max2, a);
    }
    bool flag = false;
    for (auto a : nums) {
      if (a == max1 || a == max2) {
        continue;
      }
      ret = max(ret, a);
      if (flag == false) {
        flag = true;
      }
    }
    if (flag == false) {
      ret = max1;
    }
    return ret;
  }
};