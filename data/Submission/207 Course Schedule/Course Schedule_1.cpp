//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 207 Course Schedule
// https://leetcode.com//problems/course-schedule/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 19 ms
// This solution defeats 20.99% cpp solutions

class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (numCourses < 2) {
      return true;
    }
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> graph(numCourses);
    for (auto it = prerequisites.begin(); it != prerequisites.end(); it++) {
      graph[it->first].push_back(it->second);
      indegree[it->second]++;
    }
    queue<int> q;
    int count = 0;
    vector<int> visited(numCourses, false);
    for (int i = 0; i < indegree.size(); i++) {
      if (indegree[i] == 0) {
        q.push(i);
        count++;
        visited[i] = true;
      }
    }
    if (count == 0) {
      return false;
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < graph[v].size(); i++) {
        indegree[graph[v][i]]--;
        if (visited[graph[v][i]] == false && indegree[graph[v][i]] == 0) {
          count++;
          q.push(graph[v][i]);
          visited[graph[v][i]] = true;
        }
      }
    }
    return count == numCourses;
  }
};