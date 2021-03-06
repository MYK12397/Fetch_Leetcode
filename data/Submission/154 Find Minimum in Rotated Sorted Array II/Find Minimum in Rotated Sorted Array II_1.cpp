//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 154 Find Minimum in Rotated Sorted Array II
// https://leetcode.com//problems/find-minimum-in-rotated-sorted-array-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 8 ms
// This solution defeats 5.08% cpp solutions

class Solution {
 public:
  int findMin(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return min(nums[0], nums[1]);
    }
    int low = 0, high = nums.size() - 1;
    int mid = low;
    while (nums[low] >= nums[high]) {
      if (high - low == 1) {
        mid = high;
        break;
      }
      mid = (low + high) / 2;
      if (nums[low] == nums[high] && nums[low] == nums[mid]) {
        int min = nums[0];
        for (int i = 0; i < nums.size(); i++) {
          if (nums[i] < min) {
            min = nums[i];
          }
        }
        return min;
      }
      if (nums[low] <= nums[mid]) {
        low = mid;
      } else if (nums[mid] <= nums[high]) {
        high = mid;
      }
    }
    return nums[mid];
  }
};