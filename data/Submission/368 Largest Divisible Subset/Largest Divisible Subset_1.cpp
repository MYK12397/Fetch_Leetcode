//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 368 Largest Divisible Subset
// https://leetcode.com//problems/largest-divisible-subset/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 82 ms
// This solution defeats 4.28% cpp solutions

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums;
    }
    sort(nums.begin(), nums.end());
    vector<int> T(nums.size(), 0);
    vector<int> parent(nums.size(), 0);
    int m = 0;
    int mi = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] % nums[i] == 0 && T[i] < T[j] + 1) {
          T[i] = T[j] + 1;
          parent[i] = j;
        }
      }
      if (T[i] > m) {
        m = T[i];
        mi = i;
      }
    }
    vector<int> result;
    for (int i = 0; i < m; i++) {
      result.push_back(nums[mi]);
      mi = parent[mi];
    }
    return result;
  }
};