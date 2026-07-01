/**
-Given an array arr[] of positive integers, where each value represents the
number of chocolates in a packet. Each packet can have a variable number of
chocolates. There are m students, the task is to distribute chocolate packets
among m students such that - i. Each student gets exactly one packet. ii. The
difference between maximum number of chocolates given to a student and minimum
number is minimum and return that minimum possible difference.

Given an array of positive integers, Choose m elements such that max(selected) -
min(selected) is minimum.

https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int findMinDiff(vector<int> &nums, int m) {
  sort(nums.begin(), nums.end());

  int globalMin = INT_MAX;

  for (int i = 0; m + i <= nums.size(); i++) {
    int localMin = nums[m - 1 + i] - nums[i];
    globalMin = min(localMin, globalMin);
  }
  return globalMin;
}

int main() {
  vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
  int m = 3;

  cout << "Minimum difference: " << findMinDiff(arr, m) << endl;

  return 0;
}