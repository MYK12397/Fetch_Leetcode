//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 401 Binary Watch
// https://leetcode.com//problems/binary-watch/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  vector<string> hours(int nums) {
    switch (nums) {
      case 0:
        return {"0"};
      case 1:
        return {"1", "2", "4", "8"};
      case 2:
        return {"3", "5", "6", "9", "10"};
      case 3:
        return {"7", "11"};
      default:
        return vector<string>();
    }
  }
  vector<string> minutes(int nums) {
    switch (nums) {
      case 0:
        return {"00"};
      case 1:
        return {"01", "02", "04", "08", "16", "32"};
      case 2:
        return {"03", "05", "06", "09", "10", "12", "17", "18",
                "20", "24", "33", "34", "36", "40", "48"};
      case 3:
        return {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28",
                "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"};
      case 4:
        return {"15", "23", "27", "29", "30", "39", "43",
                "45", "46", "51", "53", "54", "57", "58"};
      case 5:
        return {"31", "47", "55", "59"};
      default:
        return vector<string>();
    }
  }
  vector<string> readBinaryWatch(int num) {
    vector<string> result;
    for (int k = 0; k <= num; k++) {
      vector<string> h = hours(k);
      vector<string> m = minutes(num - k);
      if (!h.empty() && !m.empty()) {
        for (auto u : h) {
          for (auto v : m) {
            result.push_back(u + ":" + v);
          }
        }
      }
    }
    return result;
  }
};