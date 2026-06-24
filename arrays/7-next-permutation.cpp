/** 31. Next Permutation
 * Given an array of integers nums, find the next permutation of nums.

 * The replacement must be in place and use only constant extra memory.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
  // int n = nums.size();
  // int right = n - 1;
  // int left = 0;
  // int nextGreaterIdx = right;

  // for (int i=n-1; i>0; i--){
  //     nextGreaterIdx = nums[i] >= nums[nextGreaterIdx] ? i : nextGreaterIdx;
  //     if(nums[i-1] < nums[i]){
  //         left = i-1;
  //         break;
  //     }
  // }

  // swap(nums[left], nums[nextGreaterIdx]);
  // sort(nums.begin()+left+1, nums.end());

  int n = nums.size();
  int dip = -1;

  // Step 1: Find the first decreasing element from the right (the "dip")
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      dip = i;
      break;
    }
  }

  // Step 2: If a dip was found, find the smallest element to its right that is larger
  if (dip >= 0)
  {
    for (int i = n - 1; i > dip; i--)
    {
      if (nums[i] > nums[dip])
      {
        swap(nums[dip], nums[i]);
        break;
      }
    }
  }

  // Step 3: Reverse the elements to the right of the dip
  // (If dip is -1, this conveniently reverses the whole array)
  reverse(nums.begin() + dip + 1, nums.end());
}