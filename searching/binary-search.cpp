#include <iostream>
#include <vector>
using namespace std;

int binarySearchIt(vector<int> &nums, int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    else if (target < nums[mid]) {
      high = mid - 1;
    }

    else if (target > nums[mid]) {
      low = mid + 1;
    }
  }
  return -1;
}

int binarySearchRec(vector<int> &nums, int target, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) {
      return mid;
    }

    else if (target < nums[mid]) {
      return binarySearchRec(nums, target, low, mid - 1);
    }

    else if (target > nums[mid]) {
      return binarySearchRec(nums, target, mid + 1, high);
    }
  }
  return -1;
}

int main() {

  int target = 4;
  vector<int> nums = {1, 4, 6, 8, 3, 2, 5};

  // int idx = binarySearchIt(nums, target);
  int idx = binarySearchRec(nums, target, 0, nums.size() - 1);
  cout << idx;

  return 0;
}