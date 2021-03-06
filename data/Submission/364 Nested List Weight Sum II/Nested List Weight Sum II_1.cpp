//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 364 Nested List Weight Sum II
// https://leetcode.com//problems/nested-list-weight-sum-ii/description/
// Fetched at 2018-07-24
// Submitted 3 months ago
// Runtime: 4 ms
// This solution defeats 1.45% cpp solutions

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
 public:
  int depth(vector<NestedInteger>& nestedList, int dep) {
    int ret = 0;
    for (int i = 0; i < nestedList.size(); i++) {
      if (nestedList[i].isInteger() == true) {
        ret = max(ret, dep + 1);
      } else {
        ret = max(ret, depth(nestedList[i].getList(), dep + 1));
      }
    }
    return ret;
  }
  int depthSumInverse(vector<NestedInteger>& nestedList, int weight) {
    int sum = 0;
    for (int i = 0; i < nestedList.size(); i++) {
      if (nestedList[i].isInteger() == true) {
        sum += weight * nestedList[i].getInteger();
      } else {
        sum += depthSumInverse(nestedList[i].getList(), weight - 1);
      }
    }
    return sum;
  }
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int dep = depth(nestedList, 0);

    return depthSumInverse(nestedList, dep);
  }
};