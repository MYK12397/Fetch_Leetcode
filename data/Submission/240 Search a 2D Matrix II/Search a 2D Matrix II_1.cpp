//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 240 Search a 2D Matrix II
// https://leetcode.com//problems/search-a-2d-matrix-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 212 ms
// This solution defeats 10.18% cpp solutions

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    const int m = matrix.size();
    const int n = matrix[0].size();
    int inx = 0, iny = n - 1;
    while (true) {
      if (matrix[inx][iny] == target) {
        return true;
      }
      if (matrix[inx][iny] > target) {
        if (iny == 0) {
          return false;
        } else
          iny--;
      } else {
        if (inx >= m - 1) {
          return false;
        } else
          inx++;
      }
    }
    return false;
  }
};