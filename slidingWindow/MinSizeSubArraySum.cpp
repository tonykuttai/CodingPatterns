/**
 * Given an array of positive integers and a number ‘S,’ find the length of the smallest 
 * contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.
 **/
using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int minWsize{numeric_limits<int>::max()};
    for(int wEnd{0},wSum{0},wStart{0};wEnd < arr.size();wEnd++){
        wSum += arr[wEnd];
        while(wSum >= S){          
                minWsize = min(minWsize, wEnd - wStart + 1);
                wSum -= arr[wStart];
                wStart++;           
        }
    }
    
    return minWsize == numeric_limits<int>::max()?0:minWsize;
  }
};