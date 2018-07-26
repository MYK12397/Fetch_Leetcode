//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 487 Max Consecutive Ones II
// https://leetcode.com//problems/max-consecutive-ones-ii/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 41 ms
// This solution defeats 2.84% cpp solutions

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_val = 1;

    int start = 0;
    int end = 0;
    while (start < nums.size()) {
      end = start;
      while (end < nums.size() && nums[end] == 1) {
        end++;
      }
      if (end >= nums.size()) {
        max_val = max(max_val, end - start);
        break;
      }
      int end2 = end + 1;
      while (end2 < nums.size() && nums[end2] == 1) {
        end2++;
      }

      max_val = max(max_val, end2 - start);

      start = end + 1;
    }

    return max_val;
  }
};