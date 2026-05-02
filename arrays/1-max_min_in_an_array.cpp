/**
 * Given an array of integers arr[], the task is to find the maximum and minimum elements in the array using the minimum number of comparisons.
 */

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// Sorting the array
/**
 * Number of comparisons = O(N logN)
 */
vector<int> findMinMax_sort(vector<int> &arr)
{
  vector<int> sortedArr = arr;
  sort(sortedArr.begin(), sortedArr.end());
  return {sortedArr[0], sortedArr[sortedArr.size() - 1]};
}

// Iteration method
/**
 * Number of comparisons = 2N (N comparisons to find min, another N for max)
 */
vector<int> findMinMax_it(vector<int> &arr)
{
  int min = INT_MAX;
  int max = INT_MIN;

  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] < min)
      min = arr[i];
    if (arr[i] > max)
      max = arr[i];
  }
  return {min, max};
}

int main()
{
  vector<int> arr = {3, 5, 4, 1, 9};
  // vector<int> result = findMinMax_sort(arr);
  vector<int> result = findMinMax_it(arr);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}