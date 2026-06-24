/** 53. MAXIMUM SUBARRAY
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute-force
int maxSubarray(vector<int> &nums)
{
  int sum = nums[0];
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    int localSum = 0;
    for (int j = i; j < n; j++)
    {
      localSum += nums[j];
      sum = max(sum, localSum);
    }
  }
  return sum;
}

int maxSubarrayKD(vector<int> &nums)
{
  int ans = nums[0];
  int runningSum = 0;
  int n = nums.size();
  int left = 0, right = 0;

  while (right < n)
  {
    runningSum += nums[right];
    right++;
    while (runningSum <= 0 && left < right)
    {
      runningSum -= nums[left];
      left++;
    }
    ans = max(ans, runningSum);
  }
  return ans;
}

int main()
{
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int ans = maxSubarrayKD(nums);
  cout << ans;
  return 0;
}