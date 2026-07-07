#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  int minVal = INT_MAX;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    // left subarray is sorted
    if (nums[left] <= nums[mid]) {
      minVal = min(minVal, nums[left]);
      left = mid + 1;
    }
    // right subarray is sorted
    else {
      minVal = min(minVal, nums[mid]);
      right = mid - 1;
    }
  }
  return minVal;
}

int main() {

  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  // vector<int> nums = {-1, 4, -4, 5, -2, -1, -1, -2, -3};
  cout << findMin(nums);
  return 0;
}