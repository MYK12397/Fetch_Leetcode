//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 273 Integer to English Words
// https://leetcode.com//problems/integer-to-english-words/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 19 ms

class Solution {
 public:
  string numberToWords3(int num) {
    if (num == 0) {
      return "";
    }
    map<int, string> bits1;
    bits1.insert({0, "Zero"});
    bits1.insert({1, "One"});
    bits1.insert({2, "Two"});
    bits1.insert({3, "Three"});
    bits1.insert({4, "Four"});
    bits1.insert({5, "Five"});
    bits1.insert({6, "Six"});
    bits1.insert({7, "Seven"});
    bits1.insert({8, "Eight"});
    bits1.insert({9, "Nine"});
    map<int, string> bits2;
    bits2.insert({10, "Ten"});
    bits2.insert({11, "Eleven"});
    bits2.insert({12, "Twelve"});
    bits2.insert({13, "Thirteen"});
    bits2.insert({14, "Fourteen"});
    bits2.insert({15, "Fifteen"});
    bits2.insert({16, "Sixteen"});
    bits2.insert({17, "Seventeen"});
    bits2.insert({18, "Eighteen"});
    bits2.insert({19, "Nineteen"});
    bits2.insert({2, "Twenty"});
    bits2.insert({3, "Thirty"});
    bits2.insert({4, "Forty"});
    bits2.insert({5, "Fifty"});
    bits2.insert({6, "Sixty"});
    bits2.insert({7, "Seventy"});
    bits2.insert({8, "Eighty"});
    bits2.insert({9, "Ninety"});
    if (num % 100 == 0) {
      return bits1[num / 100] + " Hundred";
    }
    string result;
    int end2 = num % 100;
    num /= 100;
    if (end2 <= 19 && end2 >= 10) {
      result = bits2[end2] + result;
    } else if (end2 <= 9 && end2 > 0) {
      result = bits1[end2] + result;
    } else {
      if (end2 % 10 == 0) {
        result = bits2[end2 / 10] + result;
      } else {
        result = bits2[end2 / 10];
        result = result + " " + bits1[end2 % 10];
      }
    }
    if (num != 0) {
      result = bits1[num] + " Hundred " + result;
    }
    return result;
  }
  string numberToWords(int num) {
    if (num == 0) {
      return "Zero";
    }
    map<int, string> bit;
    bit.insert({1, "Thousand"});
    bit.insert({2, "Million"});
    bit.insert({3, "Billion"});
    bit.insert({4, "Trillion"});
    vector<int> cut;
    while (num) {
      int a = num % 1000;
      cut.push_back(a);
      num /= 1000;
    }
    string result;
    int n = cut.size();
    for (int i = n - 1; i >= 0; i--) {
      if (cut[i] != 0) {
        result = result + " " + numberToWords3(cut[i]) + " " + bit[i];
      }
    }
    auto it = result.begin();
    while (*it == ' ') {
      it = result.erase(it);
    }
    int j = result.size() - 1;
    while (result[j] == ' ') {
      j--;
    }
    result.erase(j + 1);
    return result;
  }
};