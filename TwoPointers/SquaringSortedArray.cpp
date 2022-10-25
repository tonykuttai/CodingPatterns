/*
Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]
*/

#include <iostream>
#include <vector>
using namespace std;

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int left{0},right{n-1},next{n-1};
    while(left <= right){
        if(abs(arr[left]) < abs(arr[right])){
            squares[next--] = arr[right]*arr[right];
            right--;
        }else{
            squares[next--] = arr[left]*arr[left];
            left++;
        }
    }
   
    return squares;
  }
};