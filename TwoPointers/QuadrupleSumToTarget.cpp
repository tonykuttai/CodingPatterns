/*
Given an array of unsorted numbers and a target number, find all unique quadruplets in it, 
whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& obj){
    for(auto e : obj){
        os << e << " ";
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os,const vector<vector<T>>& obj){
    for(auto e : obj){
        os << e << endl;
    }
    return os;
}

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    sort(arr.begin(),arr.end());
    int n = arr.size(),left{0},right{0},currSum{0};
    for(int p = 0; p < n-3; p++){
        for(int q = p+1;q < n-2; q++){
            if(arr[q] == arr[p]){
                // skip the duplicates
                // continue;
            }
            left = q+1;
            right = n-1;
            while(left < right){                
                currSum = arr[p] + arr[q] + arr[left] + arr[right];
                if(currSum == target){
                    // found the quadruplets
                    quadruplets.push_back({arr[p],arr[q],arr[left],arr[right]});
                    int l = arr[left];
                    while(l == arr[left]){
                        left++;
                    }
                    int r = arr[right];
                    while(r == arr[right]){
                        right--;
                    }
                }else if(currSum > target){
                    right--;
                }else{
                    left++;
                }                
            }
        }
    }
    return quadruplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {4, 1, 2, -1, 1, -3};
  auto result = QuadrupleSumToTarget::searchQuadruplets(vec, 1);
  cout << result;
//   for (auto vec : result) {
//     cout << "[";
//     for (auto num : vec) {
//       cout << num << " ";
//     }
//     cout << "]";
//   }
//   cout << endl;

//   vec = {2, 0, -1, 1, -2, 2};
//   result = QuadrupleSumToTarget::searchQuadruplets(vec, 2);
//   for (auto vec : result) {
//     cout << "[";
//     for (auto num : vec) {
//       cout << num << " ";
//     }
//     cout << "]";
//   }
}