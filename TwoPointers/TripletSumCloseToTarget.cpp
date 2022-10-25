/*
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as 
close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
Example 3:

Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int> &arr,int targetSum) {
    int start{0},end{0},smallestDiff{numeric_limits<int>::max()};
    int n = arr.size();
    //sort the input array
    sort(arr.begin(),arr.end()); //O(NlogN)
    for(int i = 0;i < n;i++){
        start = i+1;
        end = n-1;
        while(start < end){
            int targetDiff = targetSum - arr[i] - arr[start] - arr[end];
            if(targetDiff == 0){
               return targetSum;   
            }else if(targetDiff > 0){                
                end--;
            }else{
                start++;
            }
            if((abs(targetDiff) < abs(smallestDiff)) || (abs(targetDiff) == abs(smallestDiff) && targetDiff > smallestDiff)){
                smallestDiff = targetDiff;
            }        
        }
    }
    return targetSum - smallestDiff;
  }
};

