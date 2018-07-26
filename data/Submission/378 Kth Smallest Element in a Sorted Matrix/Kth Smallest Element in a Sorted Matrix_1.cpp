//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 378 Kth Smallest Element in a Sorted Matrix
// https://leetcode.com//problems/kth-smallest-element-in-a-sorted-matrix/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 93 ms
// This solution defeats 3.2% cpp solutions

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<int> dp;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + 1) * (j + 1) <= k) {
          dp.push_back(matrix[i][j]);
        } else {
          break;
        }
      }
    }
    sort(dp.begin(), dp.end());
    return dp[k - 1];
  }
};