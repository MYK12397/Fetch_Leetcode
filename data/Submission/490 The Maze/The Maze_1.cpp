//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 490 The Maze
// https://leetcode.com//problems/the-maze/description/
// Fetched at 2018-07-24
// Submitted 3 months, 1 week ago
// Runtime: 32 ms
// This solution defeats 17.82% cpp solutions

class Solution {
 public:
  bool DFS(vector<vector<int>>& maze, vector<vector<bool>>& visited,
           vector<int> start, vector<int>& dest) {
    if (visited[start[0]][start[1]] == true) {
      return false;
    }
    visited[start[0]][start[1]] = true;
    if (start[0] == dest[0] && start[1] == dest[1]) {
      return true;
    }
    int i;
    if (start[0] - 1 >= 0 && visited[start[0] - 1][start[1]] != true &&
        maze[start[0] - 1][start[1]] != 1) {
      i = 1;
      while (start[0] - i >= 0 && maze[start[0] - i][start[1]] != 1) {
        i++;
      }
      i--;
      if (DFS(maze, visited, vector<int>{start[0] - i, start[1]}, dest)) {
        return true;
      }
    }
    if (start[0] + 1 < maze.size() && visited[start[0] + 1][start[1]] != true &&
        maze[start[0] + 1][start[1]] != 1) {
      i = 1;
      while (start[0] + i < maze.size() && maze[start[0] + i][start[1]] != 1) {
        i++;
      }
      i--;
      if (DFS(maze, visited, vector<int>{start[0] + i, start[1]}, dest)) {
        return true;
      }
    }
    if (start[1] - 1 >= 0 && visited[start[0]][start[1] - 1] != true &&
        maze[start[0]][start[1] - 1] != 1) {
      i = 1;
      while (start[1] - i >= 0 && maze[start[0]][start[1] - i] != 1) {
        i++;
      }
      i--;
      if (DFS(maze, visited, vector<int>{start[0], start[1] - i}, dest)) {
        return true;
      }
    }
    if (start[1] + 1 < maze[0].size() &&
        visited[start[0]][start[1] + 1] != true &&
        maze[start[0]][start[1] + 1] != 1) {
      i = 1;
      while (start[1] + i < maze[0].size() &&
             maze[start[0]][start[1] + i] != 1) {
        i++;
      }
      i--;
      if (DFS(maze, visited, vector<int>{start[0], start[1] + i}, dest)) {
        return true;
      }
    }
    return false;
  }

  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    vector<vector<bool>> visited(maze.size(),
                                 vector<bool>(maze[0].size(), false));

    return DFS(maze, visited, start, destination);
  }
};