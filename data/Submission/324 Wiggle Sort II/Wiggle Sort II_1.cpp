//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 324 Wiggle Sort II
// https://leetcode.com//problems/wiggle-sort-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 76 ms
// This solution defeats 16.25% cpp solutions

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return;
    sort(nums.begin(), nums.end());
    vector<int> result(nums);
    int j = len - 1;
    for (int i = 1; i < len; i += 2, j--) result[i] = nums[j];
    for (int i = 0; i < len; i += 2, j--) result[i] = nums[j];
    nums = result;
    return;
  }
};