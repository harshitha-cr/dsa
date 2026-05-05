/**
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
  unordered_map<int, int> lookup;
  for (int i = 0; i < nums.size(); i++)
  {
    // key:value = nums:index
    lookup[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (lookup.count(nums[i]) && lookup.at(nums[i]) != i)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool result = containsDuplicate(nums);
  cout << result;
  return 0;
}