/*
Given an array containing 0s, 1s and 2s, sort the array in-place. 
You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; 
and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Example 2:

Input: [2, 2, 0, 1, 2, 0]
Output: [0, 0, 1, 2, 2, 2,]
*/

#include <iostream>
#include <vector>
using namespace std;
class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    int n = arr.size();
    int low{0},high{n-1};
    for(int k = 0;k <= high;){
        if(arr[k] == 0){
            //swap with element at the low pointer
            swap(arr[k],arr[low]);
            low++;
            k++;
        }else if(arr[k] == 1){
            // increment k
            k++;
        }else{
            // swap with element at the high pointer
            swap(arr[k],arr[high]);
            high--;
        }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 0, 2, 1, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 2, 0, 1, 2, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
}