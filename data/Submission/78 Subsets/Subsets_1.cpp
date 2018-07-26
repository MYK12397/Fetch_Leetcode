//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 78 Subsets
// https://leetcode.com//problems/subsets/description/
// Fetched at 2018-07-24
// Submitted 3 months, 1 week ago
// Runtime: 7 ms
// This solution defeats 2.15% cpp solutions

class Solution {
 public:
  void backtrace(vector<int>& nums, int low, int high,
                 vector<vector<int>>& ret) {
    if (high <= low) {
      return;
    }
    backtrace(nums, low, high - 1, ret);
    int n = ret.size();
    for (int i = 0; i < n; i++) {
      vector<int> temp = ret[i];
      temp.push_back(nums[high - 1]);
      ret.push_back(temp);
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>{});
    backtrace(nums, 0, nums.size(), ret);
    return ret;
  }
};