/* 
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11 
*/

#include <iostream>
#include <vector>
using namespace std;

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int start{0},currSum{0},end = arr.size()-1;
    while(start < end){
        currSum = arr[start] + arr[end];
        if(currSum == targetSum){
            // Pair found
            return {start,end};
        }else if(currSum > targetSum){
            end--;
        }else{
            start++;
        }
    }
    return make_pair(-1, -1);
  }
};