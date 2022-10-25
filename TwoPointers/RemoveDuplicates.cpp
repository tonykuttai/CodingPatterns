/*
Given an array of sorted numbers, remove all duplicate number instances from it in-place, 
such that each element appears only once. The relative order of the elements should be kept the 
same and you should not use any extra space so that that the solution have a space complexity of O(1).

Move all the unique elements at the beginning of the array and after moving return the length of the subarray that has no duplicate in it.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].
*/

#include <iostream>
#include <vector>
using namespace std;

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    // TODO: Write your code here
    int nextNonDuplicate = 1; //index to the next nonduplicate element
    for(int i = 1;i <arr.size();i++){
        if(arr[nextNonDuplicate-1] != arr[i]){
            arr[nextNonDuplicate] = arr[i];
            nextNonDuplicate++;
        }
    }
    return nextNonDuplicate;
  }
};