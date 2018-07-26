//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 309 Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 8 ms
// This solution defeats 12.5% cpp solutions

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int i, sz = prices.size();
    int ret = 0;
    vector<int> buy(sz, 0);
    vector<int> sell(sz, 0);
    buy[0] = -prices[0];
    buy[1] = buy[0] + prices[0] - prices[1];
    sell[1] = max(buy[0] + prices[1], sell[0] - prices[0] + prices[1]);
    ret = max(sell[1], sell[0]);
    for (i = 2; i < sz; ++i) {
      sell[i] =
          max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
      if (ret < sell[i]) ret = sell[i];
      buy[i] =
          max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
    }
    return ret;
  }
};