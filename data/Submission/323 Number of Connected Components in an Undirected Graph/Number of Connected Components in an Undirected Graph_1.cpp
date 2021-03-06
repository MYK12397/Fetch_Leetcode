//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 323 Number of Connected Components in an Undirected Graph
// https://leetcode.com//problems/number-of-connected-components-in-an-undirected-graph/description/
// Fetched at 2018-07-24
// Submitted 3 months ago
// Runtime: 13 ms
// This solution defeats 19.44% cpp solutions

class Solution {
 public:
  int num_visit = 0;
  void DFS(vector<vector<int>>& adjects, vector<bool>& visited, int start) {
    visited[start] = true;
    num_visit++;
    for (int i = 0; i < adjects[start].size(); i++) {
      if (visited[adjects[start][i]] != true) {
        DFS(adjects, visited, adjects[start][i]);
      }
    }
  }
  int countComponents(int n, vector<pair<int, int>>& edges) {
    if (n == 0) {
      return 0;
    }
    vector<bool> visited(n, false);
    vector<vector<int>> adjects(n, vector<int>());
    for (int i = 0; i < edges.size(); i++) {
      adjects[edges[i].first].push_back(edges[i].second);
      adjects[edges[i].second].push_back(edges[i].first);
    }
    int ret = 1;
    DFS(adjects, visited, 0);
    while (num_visit < n) {
      ret++;
      for (int i = 1; i < n; i++) {
        if (visited[i] != true) {
          DFS(adjects, visited, i);
          break;
        }
      }
    }
    return ret;
  }
};