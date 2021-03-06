//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 345 Reverse Vowels of a String
// https://leetcode.com//problems/reverse-vowels-of-a-string/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 36 ms
// This solution defeats 4.04% cpp solutions

class Solution {
 public:
  string reverseVowels(string s) {
    if (s.empty()) {
      return s;
    }
    string result = s;
    const string vowel = "aeiouAEIOU";
    int low = 0, high = s.size() - 1;
    while (low < high) {
      if (find(vowel.begin(), vowel.end(), result[low]) != vowel.end() &&
          find(vowel.begin(), vowel.end(), result[high]) != vowel.end()) {
        swap(result[low], result[high]);
        low++;
        high--;
      } else if (find(vowel.begin(), vowel.end(), result[low]) == vowel.end()) {
        do
          low++;
        while (find(vowel.begin(), vowel.end(), result[low]) == vowel.end());
      } else {
        do
          high--;
        while (find(vowel.begin(), vowel.end(), result[high]) == vowel.end());
      }
    }
    return result;
  }
};