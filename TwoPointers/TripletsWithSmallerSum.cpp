/*
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that 
arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
*/



#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = 0;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int currSum{0};
    for(int k = 0;k < n; k++){
        int left = k+1;
        int right = n-1;
        while(left < right){
            currSum = arr[k] + arr[left] + arr[right];
            if(currSum < target){
                count += right-left;
                left++;
            }else{
                right--;
            }
        }

    }
    return count;
  }
};


int main(int argc, char *argv[]) {
  vector<int> vec = {-1, 0, 2, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 3) << endl;
  vec = {-1, 4, 2, 1, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 5) << endl;
}


