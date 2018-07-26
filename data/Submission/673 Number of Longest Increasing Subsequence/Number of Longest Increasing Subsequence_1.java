// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 673 Number of Longest Increasing Subsequence
// https://leetcode.com//problems/number-of-longest-increasing-subsequence/description/
// Fetched at 2018-07-24
// Submitted 1 month, 1 week ago
// Runtime: 37 ms
// This solution defeats 7.62% java solutions

class Solution {
  public int binarySearch(ArrayList<Integer> list, int target) {
    if (list.size() == 0) return 0;
    int low = 0, high = list.size() - 1, mid = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      if (list.get(mid) == target) return mid;
      else if (list.get(mid) < target) low = mid + 1;
      else high = mid - 1;
    }
    return low;
  }

  public int findNumberOfLIS(int[] nums) {
    if (nums.length == 0) return 0;
    int[][] dp = new int[nums.length][2];
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < nums.length; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] > nums[j]) dp[i][0] = Math.max(dp[i][0], dp[j][0] + 1);
      }
      dp[i][0] = Math.max(dp[i][0], 1);
      for (int j = i - 1; j >= 0; j--) {
        if (dp[i][0] == dp[j][0] + 1 && nums[i] > nums[j]) dp[i][1] += dp[j][1];
      }
      dp[i][1] = Math.max(dp[i][1], 1);
    }
    int ret = 0, max_len = 0;
    for (int i = 0; i < dp.length; i++) max_len = Math.max(dp[i][0], max_len);
    for (int i = 0; i < dp.length; i++) {
      if (dp[i][0] == max_len) ret += dp[i][1];
    }
    return ret;
  }
}