//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 221 Maximal Square
// https://leetcode.com//problems/maximal-square/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 24 ms
// This solution defeats 8.1% cpp solutions

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }
    auto check = [&matrix](const int i, const int j, const int k) -> bool {
      for (int x = i; x <= k + i; x++) {
        for (int y = j; y <= k + j; y++) {
          if (x >= matrix.size() || y >= matrix[0].size() ||
              matrix[x][y] == '0')
            return false;
        }
      }
      return true;
    };
    int k = 0, max = 0;
    for (int i = 0; i < matrix.size(); i++)
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == '1') {
          if (max > 0) {
            k = max;
          } else
            k = 1;
          while (true) {
            if (check(i, j, k) == true) {
              k++;
            } else
              break;
          }
          if (k > max) max = k;
        }
      }
    return max * max;
  }
};