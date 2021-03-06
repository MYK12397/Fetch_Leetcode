//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 357 Count Numbers with Unique Digits
// https://leetcode.com//problems/count-numbers-with-unique-digits/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n > 10) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 10;
    for (int i = 2; i <= n; i++) {
      dp[i] += dp[i - 1];
      int mul = 9;
      for (int j = 0; j < i - 1; j++) {
        mul *= 9 - j;
      }
      dp[i] += mul;
    }
    return dp[n];
  }
};