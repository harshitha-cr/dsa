/**
 * Given an integer array nums, return true if any value appears at least twice
 in the array, and return false if every element is distinct.

 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Two pass
bool containsDuplicateTP(vector<int> &nums) {
  unordered_map<int, int> lookup;
  for (int i = 0; i < nums.size(); i++) {
    // nums:index
    lookup[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (lookup.count(nums[i]) && lookup.at(nums[i]) != i) {
      return true;
    }
  }
  return false;
}

// One Pass
bool containsDuplicateOP(vector<int> &nums) {
  unordered_map<int, int> lookup;
  for (int i = 0; i < nums.size(); i++) {
    if (lookup.count(nums[i]) && lookup.at(nums[i]) != i) {
      return true;
    } else {
      lookup[nums[i]] = i;
    }
  }
  return false;
}

int main() {
  vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool result = containsDuplicateOP(nums);
  for (int n : nums) {
    cout << n << " ";
  }
  cout << "\n" << result;
  return 0;
}