/*
You are at index i.

You move:
right if nums[i] > 0
left if nums[i] < 0
The array is circular. hence wrap it to [0, n-1]
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> transformedArray(vector<int>& nums){
  int n = nums.size();
  vector<int> results(n);

  for(int i = 0; i < n; i++){
    //int idx = ((i+ nums[i]) % n + n) % n;
  }
}

int main(){
  return 0;
}
