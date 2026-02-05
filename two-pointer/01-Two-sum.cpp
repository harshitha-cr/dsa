/*
Two pass and One pass:
Copy all elements & then search or do something

Check and copy simultaneously, if possible.

unordered_map.count(key) 
The unordered_map::count() is a builtin method in C++ which is used to count the number of elements present in an unordered_map with a given key. 
Note: As unordered_map does not allow to store elements with duplicate keys, so the count() function basically checks if there exists an element in the unordered_map with a given key or not.

returns 1 if there exists a value in the map with the given key, otherwise it returns 0.

ANOTHER WAY TO CHECK IF KEY:VALUE EXISTS

unordered_map.find(key) != unordered_map.end() ;

find() return end iterator if key:value doesnt exist 
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


// O(n^2) & O(1)
vector<int> bruteForce(vector<int>& nums, int target){
  for(int i=0; i<nums.size(); i++){
    for(int j=i+1; j<nums.size(); j++){
      int sum = nums[i] + nums[j];
      if(sum == target){
        return {i,j};
      }
    }
  }
  return {};
}


// my jugad for sorted array input
// workes only for positive arrays though
vector<int> jugad(vector<int>& nums, int target){
  int subIndex = nums.size();  //default 

  // finding subIndex to reduce the looping over, its waste and this limits teh negative numbers testcase
  for(int i=0; i<nums.size(); i++){
    if(nums[i] > target){
      subIndex = i;
      break;
    }
  }

  // O(n) & O(1)
  // Only this part can work for all sorted arrays (neg included) if subIndex = nums.size() i.e., iteration over entire array
  int start = 0;
  int end = subIndex-1;
  while(start < end){
    int sum = nums[start] + nums[end];
    if(sum == target){
      // outputIndex.push_back(start);
      // outputIndex.push_back(end);
      // break;
      return {start, end};
    }
    // handle increment decrement
    else if(sum < target){
      start++;
    }
    else if(sum > target){
      end--;
    }
  }
  return {};
}



// O(n) [O(n) + O(n)] & O(n)
// Two-pass Hash Table
vector<int> Twopass(vector<int>& nums, int target){
  // Step 1: Create a map to store numbers and their indices
  unordered_map<int, int> lookup;

  // Step 2: Add each number and its index to the map.
  for(int i=0; i<nums.size(); i++){
    //nums -> index 
    lookup[nums[i]] = i;
  }

  // Step 3: Check for each number, if its complement exists in the map.
  for(int i=0; i<nums.size(); i++){
    int complement = target - nums[i];

    // Ensure the complement is not the number itself.
    if(lookup.count(complement) && (lookup[complement != i])){
      // Step 4: If the complement exists, the indices are returned.
      return {i, lookup[complement]};
    } 
  }

  // Step 5: If no two numbers sum up to the target, return an empty vector.
  return {};
}



/*
Since we are checking first and then adding elements, there is no chance of same element(index i) being the complement also.
if we follow this, then for the actual pair, we'll be checking the number whose index > complement
hence return {numMap[complement], i}; 
*/
vector<int> Onepass(vector<int>& nums, int target){
  // Step 1: Again, create a map to store numbers and their indices.
  unordered_map<int, int> numMap;

  // Step 2: During iteration over the numbers, the complement is calculated for each number.
  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    // Step 3: It checks if the complement exists in the map. If so, the indices are returned.
    if (numMap.count(complement)) {
      return {numMap[complement], i};
    }
    // Step 4: Otherwise, the current number and its index are added to the map.
    numMap[nums[i]] = i;
  }
  // Step 5: If no pair sums up to the target, return an empty vector.
  return {};
}

int main(){
  vector<int> nums {3,2,4};
  // by sorting, im loosing the original index of numbers. 
  // sort(nums.begin(), nums.end());
  int target = 6;




  vector<int> output = bruteForce(nums, target);
  for(int i:output){
    cout<<i<<" ";
  }

  return 0;
}
