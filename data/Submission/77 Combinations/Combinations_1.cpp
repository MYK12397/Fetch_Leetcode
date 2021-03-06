//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 77 Combinations
// https://leetcode.com//problems/combinations/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 82 ms
// This solution defeats 22.5% cpp solutions

class Solution {
 public:
  void next(vector<int>& nums, int n) {
    if (nums.back() < n) {
      nums.back()++;
      return;
    }
    int i = nums.size() - 2;
    while (i >= 0) {
      if (nums[i] + 1 < nums[i + 1]) {
        nums[i]++;
        nums[i + 1] = nums[i] + 1;
        for (int j = i + 2; j < nums.size(); j++) {
          nums[j] = nums[j - 1] + 1;
        }
        return;
      } else {
        i--;
      }
    }
  }
  long long int fact(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    if (k > n) {
      return result;
    }
    vector<int> nums;
    for (int i = 1; i <= k; i++) {
      nums.push_back(i);
    }
    long long int len = fact(n) / (fact(n - k) * fact(k));
    while (result.size() < len) {
      result.push_back(nums);
      next(nums, n);
    }
    return result;
  }
};