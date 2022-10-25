using namespace std;

#include <iostream>
#include <vector>
/**
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 **/

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) { //O(N)
    int maxSum = 0;
    int wSum = 0;
    for(int wEnd = 0; wEnd < arr.size(); wEnd++){
        wSum += arr[wEnd];
        if(wEnd >= k-1){
            maxSum = (wSum > maxSum)?wSum:maxSum;
            wSum -= arr[wEnd-k+1];
        }
    }
    return maxSum;
  }
};