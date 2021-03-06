//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 189 Rotate Array
// https://leetcode.com//problems/rotate-array/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 24 ms
// This solution defeats 27.39% cpp solutions

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    if (k < 1 || nums.size() < 2) {
      return;
    }
    stack<int> Q;
    for (int j = 0; j < k; j++) {
      Q.push(nums[nums.size() - 1 - j]);
    }
    for (int i = nums.size() - k - 1; i >= 0; i--) {
      nums[i + k] = nums[i];
    }
    int i = 0;
    while (!Q.empty()) {
      nums[i] = Q.top();
      Q.pop();
      i++;
    }
  }
};