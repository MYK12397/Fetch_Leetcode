//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 73 Set Matrix Zeroes
// https://leetcode.com//problems/set-matrix-zeroes/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 66 ms
// This solution defeats 2.34% cpp solutions

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    map<pair<int, int>, int> hash;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == INT_MAX) {
          hash[{i, j}] = 1;
        }
      }
    }
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          for (int k = 0; k < matrix[i].size(); k++) {
            if (matrix[i][k] == INT_MAX) {
              hash.erase({i, k});
            }
            if (matrix[i][k] != 0) {
              matrix[i][k] = INT_MAX;
            }
          }
          for (int k = 0; k < matrix.size(); k++) {
            if (matrix[k][j] == INT_MAX) {
              hash.erase({k, j});
            }
            if (matrix[k][j] != 0) {
              matrix[k][j] = INT_MAX;
            }
          }
        }
      }
    }
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == INT_MAX &&
            hash.find(make_pair(i, j)) == hash.end()) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};