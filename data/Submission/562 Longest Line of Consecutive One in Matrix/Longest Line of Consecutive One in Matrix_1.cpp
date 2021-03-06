//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 562 Longest Line of Consecutive One in Matrix
// https://leetcode.com//problems/longest-line-of-consecutive-one-in-matrix/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 51 ms
// This solution defeats 16.67% cpp solutions

class Solution {
 public:
  void search(vector<vector<int>>& M, int i, int j, int state,
              vector<vector<int>>& dp, int& ret) {
    int k = 1;
    if (state == 1) {
      while (j < M[0].size() && M[i][j] == 1) {
        dp[i][j] = k;
        j++;
        k++;
      }
      ret = max(ret, k - 1);
    } else if (state == 2) {
      while (i < M.size() && M[i][j] == 1) {
        dp[i][j] = k;
        i++;
        k++;
      }
      ret = max(ret, k - 1);
    } else if (state == 3) {
      while (i < M.size() && j < M[0].size() && M[i][j] == 1) {
        dp[i][j] = k;
        i++;
        j++;
        k++;
      }
      ret = max(ret, k - 1);
    } else if (state == 4) {
      while (i < M.size() && j >= 0 && M[i][j] == 1) {
        dp[i][j] = k;
        i++;
        j--;
        k++;
      }
      ret = max(ret, k - 1);
    }
  }
  int longestLine(vector<vector<int>>& M) {
    if (M.empty()) {
      return 0;
    }
    int m = M.size(), n = M[0].size();
    int ret = 0;
    vector<vector<int>> dp1(m, vector<int>(n, 0));
    vector<vector<int>> dp2(m, vector<int>(n, 0));
    vector<vector<int>> dp3(m, vector<int>(n, 0));
    vector<vector<int>> dp4(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (M[i][j] == 1) {
          if (dp1[i][j] == 0) {
            search(M, i, j, 1, dp1, ret);
          }
          if (dp2[i][j] == 0) {
            search(M, i, j, 2, dp2, ret);
          }
          if (dp3[i][j] == 0) {
            search(M, i, j, 3, dp3, ret);
          }
          if (dp4[i][j] == 0) {
            search(M, i, j, 4, dp4, ret);
          }
          if (ret >= max(m, n)) {
            return ret;
          }
        }
      }
    }
    return ret;
  }
};