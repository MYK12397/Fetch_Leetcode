//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 287 Find the Duplicate Number
// https://leetcode.com//problems/find-the-duplicate-number/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 26 ms
// This solution defeats 8.65% cpp solutions

class Solution {
 public:
  int binary_search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int mid;
    while (high >= low) {
      mid = (low + high) / 2;
      if (target == nums[mid]) {
        while (mid >= 0 && nums[mid] == target) {
          mid--;
        }
        return mid + 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
  int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size() - 1;
    for (int i = 1; i <= n;) {
      int tags = binary_search(nums, i);
      if (tags >= 0 && tags + 1 < nums.size() && nums[tags + 1] == i) {
        return i;
      } else {
        i++;
      }
    }
    return -1;
  }
};