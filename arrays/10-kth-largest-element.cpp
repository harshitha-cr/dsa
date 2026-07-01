/**
Given an integer array nums and an integer k, return the kth largest element in
the array.

Note that it is the kth largest element in the sorted order, not the kth
distinct element.

Can you solve it without sorting?
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 - Using minHeap
 - Maintain a minHeap of size k, if size increases remove smallest (i.e., top)
 - Return the kth largest element (i.e., top)

 - TC: O(n logk) - O(logk) for each insertion. There are n insertions.
 - SC: O(k)
 */
int findKthLargestMinH(vector<int> &nums, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int &num : nums) {
    pq.push(num);
    if (pq.size() > k) {
      pq.pop();
    }
  }
  return pq.top();
}

/*
 - Using maxHeap
 - Build a maxHeap of n elements. Remove k-1 elements. Return kth largest
 Element

 - TC: O(n logn)
 - SC: O(n)
 */
int findKthLargestMaxH(vector<int> &nums, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int &num : nums) {
    pq.push(num);
  }
  while (k > 1) {
    pq.pop();
    k--;
  }
  return pq.top();
}

int main() {
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 7};
  int k = 4;
  int ans = findKthLargestMinH(nums, k);
  cout << ans;
  return 0;
}
