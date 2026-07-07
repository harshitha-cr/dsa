#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums) {
  // Initialize: maxProd tracks maximum product ending at current position
  // minProd tracks minimum product ending at current position (for handling
  // negative numbers) result stores the global maximum product found so far

  int maxEnding = nums[0];
  int minEnding = nums[0];
  int ans = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    // Store previous values before updating
    int prevMax = maxEnding;
    int prevMin = minEnding;

    // Update maximum product ending at current position
    // Consider three cases:
    // 1. Start fresh with current number alone
    // 2. Extend prev maximum product
    // 3. Extend prev minimum product (useful when curr number is negative)
    maxEnding = max({nums[i], nums[i] * prevMax, nums[i] * prevMin});
    minEnding = min({nums[i], nums[i] * prevMax, nums[i] * prevMin});

    // Update global maximum result
    ans = max(ans, maxEnding);
  }
  return ans;
}

int main() {
  // vector<int> nums = {0,  10, 10, 10, 10, 10, 10, 10, 10, 10, -10,
  //                     10, 10, 10, 10, 10, 10, 10, 10, 10, 0};
  // vector<int> nums = {2, 3, -4, 2, -2};
  vector<int> nums = {-1, 4, -4, 5, -2, -1, -1, -2, -3}; // 960
  cout << maxProduct(nums);
  return 0;
}