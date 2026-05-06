/** PROBLEM STATEMENT
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.

* You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

* Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
  int buy = 0;
  int sell = 1;
  int maxProfit = 0;

  while (sell < prices.size())
  {
    if (prices[buy] < prices[sell])
    {
      // when buy < sell, check for maxProfit while moving forward in
      // array
      maxProfit = max(maxProfit, prices[sell] - prices[buy]);
    }
    else
    {
      // if buy > sell, then obv increment both.
      buy = sell;
    }
    sell++;
  }
  return maxProfit;
}

int main()
{
  // vector<int> prices = {2,4,1};
  vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9};
  int result = maxProfit(prices);
  cout << result;
}
