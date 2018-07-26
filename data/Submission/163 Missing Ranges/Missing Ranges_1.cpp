//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 163 Missing Ranges
// https://leetcode.com//problems/missing-ranges/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 3 ms

class Solution {
 public:
  string make_range(long long int lower, long long int upper) {
    if (upper - lower == 2) {
      return to_string(lower + 1);
    }
    return to_string(lower + 1) + "->" + to_string(upper - 1);
  }
  string make_range2(long long int lower, long long int upper) {
    if (upper - lower < 1) {
      return to_string(lower);
    }
    return to_string(lower) + "->" + to_string(upper);
  }
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ret;
    if (nums.empty()) {
      ret.push_back(make_range2(lower, upper));
      return ret;
    }
    if (lower < nums[0]) {
      ret.push_back(make_range2(lower, nums[0] - 1));
    }
    for (int i = 1; i < nums.size(); i++) {
      if ((long long int)(nums[i]) - (long long int)(nums[i - 1]) < 2) {
        continue;
      }
      ret.push_back(make_range(nums[i - 1], nums[i]));
    }
    if (nums.back() < upper) {
      ret.push_back(make_range2(nums.back() + 1, upper));
    }
    return ret;
  }
};