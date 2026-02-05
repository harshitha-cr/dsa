/**
167: Two Sum-II   Input Array is Sorted

- 1-indexed Array
- return indices of two values whose sum add to target
- You may not use the same element twice.
- Your solution must use only constant extra space.
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int n = numbers.size();
  int start = 0;
  int end = n-1;

  while (start < end){
    int sum = numbers[start] + numbers[end];
    if(sum == target) {
      return {start+1, end+1};
    }
    else if(sum < target){
      start++;
    }
    else end--;
  }
  return {};
}

int main(){
  vector<int> numbers {2,7,11,15};
  int target = 9;
  vector<int> ans = twoSum(numbers, target);
  for(int i:ans){
    cout<<i<<" ";
  }
}