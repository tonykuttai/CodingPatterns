/*
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Example 1:

Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
Example 2:

Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
Example 3:

Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted
Example 4:

Input: [3, 2, 1]
Output: 3
Explanation: The whole array needs to be sorted.
*/
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    int n = arr.size();
    int left{0},right{n-1},subMax{numeric_limits<int>::min()},subMin{numeric_limits<int>::max()};
    // From the beginning and end of the array, find the first elements that are out of the sorting order. 
    // The two elements will be our candidate subarray.
    while(left < n-1 && arr[left] <= arr[left+1]){
        left++;
    }
    if(left == n-1){
        return 0;// array is sorted
    }
    while(right > 0 && arr[right-1] <= arr[right]){
        right--;
    }
    // Now find the min and max of this subarray
    for(int k = left;k <= right;k++){
        subMax = max(subMax,arr[k]);
        subMin = min(subMin,arr[k]);
    }

    // extend the subarray to include any number which is bigger than the minimum of the subarray
    while(left > 0 && arr[left-1] > subMin){
        left--;
    }
    // extend the subarray to include any number which is lower than the maximum of the subarray
    while(right < n-1 && arr[right+1] < subMax){
        right++;
    }
    return (right - left + 1);
  }
};

int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 3}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{3, 2, 1}) << endl;
}