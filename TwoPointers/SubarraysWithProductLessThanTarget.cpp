/*
Given an array with positive numbers and a positive target number, find all of its contiguous 
subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10], target=30 
Output: [2], [5], [2, 5], [3], [5, 3], [10]
Explanation: There are six contiguous subarrays whose product is less than the target.
Example 2:

Input: [8, 2, 6, 5], target=50 
Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5] 
Explanation: There are seven contiguous subarrays whose product is less than the target.
*/

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    double product {1};
    int left{0};
    for(int right = 0; right < arr.size(); right++){
      product *= arr[right];
      while(product >= target && left <= right){
        product /= arr[left++];
      }
      // product of all numbers form left to right is less than the target.
      // al subarray from left to right will have a product ess than the target too;
      // to avoid duplicates we will start with subarray containing only arr[right]
      // and then extend it.
      deque<int> tempQ;
      for(int i = right; i >= left; i--){
        tempQ.push_front(arr[i]);
        vector<int> resultVec;
        std::move(std::begin(tempQ),std::end(tempQ),std::back_inserter(resultVec));
        result.push_back(resultVec);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  auto result = SubarrayProductLessThanK::findSubarrays(vector<int>{1,2, 5, 3, 9,4,7,10}, 30000);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  result = SubarrayProductLessThanK::findSubarrays(vector<int>{8, 2, 6, 5}, 50);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}

