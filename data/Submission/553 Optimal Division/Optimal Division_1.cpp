//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 553 Optimal Division
// https://leetcode.com//problems/optimal-division/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 5 ms
// This solution defeats 3.62% cpp solutions

class Solution {
 public:
  string optimalDivision(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return to_string(nums[0]);
    }
    if (n == 2) {
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string ret = "";
    for (int i = 0; i < nums.size() - 1; i++) {
      if (i == 1) {
        ret = ret + "(";
      }
      ret = ret + to_string(nums[i]);
      ret = ret + "/";
    }
    ret = ret + to_string(nums.back());
    ret = ret + ")";
    return ret;
  }
};