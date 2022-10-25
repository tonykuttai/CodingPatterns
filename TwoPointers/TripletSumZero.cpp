/*
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.


*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    int start{0},end{0},targetsum{0};
    int n = arr.size();
    //sort the input array
    sort(arr.begin(),arr.end()); //O(NlogN)
    for(int i = 0;i < n;i++){
        start = i+1;
        end = n-1;
        targetsum = -arr[i];
        while(start < end){
            int currsum = arr[start] + arr[end];
            if(currsum == targetsum){
               triplets.push_back({arr[i],arr[start],arr[end]});
               // skip the duplicates
               int k = arr[start];
               while(arr[start] == k){
                start++;
               }
               k = arr[end];
               while(arr[end] == k){
                end--;
               }          
            }else if(currsum > targetsum){
                end--;
            }else{
                start++;
            }            
        }
    }
    return triplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  auto result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-5, 2, -1, -2, 3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}