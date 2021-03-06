//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 751 Number Of Corner Rectangles
// https://leetcode.com//problems/number-of-corner-rectangles/description/
// Fetched at 2018-07-24
// Submitted 1 month, 1 week ago
// Runtime: 104 ms
// This solution defeats 69.23% cpp solutions

class Solution {
 public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ret = 0, counter = 0;
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        counter = 0;
        for (int k = 0; k < n; k++) {
          if (grid[i][k] == 1 && grid[j][k] == 1) counter++;
        }
        if (counter > 0) ret += counter * (counter - 1) / 2;
      }
    }
    return ret;
  }
};