/**
 * Reverse an array
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Using Two Pointers - O(n) Time and O(1) Space
void reverseArrayTwo(vector<int> &arr)
{
  int left = 0;
  int right = arr.size() - 1;
  while (left < right)
  {
    swap(arr[left], arr[right]);
    left++;
    right--;
  }
}

// Using Single Pointer - O(n) Time and O(1) Space
void reverseArrayOne(vector<int> &arr)
{
  int n = arr.size();
  // iterate over half array, swap each element with its corresponding element from the end
  for (int i = 0; i < n / 2; i++)
  {
    swap(arr[i], arr[n - i - 1]);
  }
}

// Using in-built function: reverse(arr.begin(), arr.end());

int main()
{
  vector<int> arr = {1, 4, 2, 6, 5};
  reverseArrayOne(arr);

  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  return 0;
}