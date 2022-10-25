/**
 * Given an array, find the average of each subarray of ‘K’ contiguous elements in it.
 * Array: [1, 3, 2, 6, -1, 4, 1, 8, 2], K=5
 * Output: [2.2, 2.8, 2.4, 3.6, 2.8]
 * 
 **/
#include <iostream>
#include <vector>

using namespace std;

class AverageOfSubArrayOfSizeK{
    public:
        static vector<double> findAverage(int k, const vector<int>& arr){
            vector<double> result;
            double windowSum = 0;
            for(int wEnd = 0; wEnd < arr.size(); wEnd++){
                windowSum += arr[wEnd];
                if(wEnd >= k-1){
                    result.push_back(windowSum/k);
                    windowSum -= arr[wEnd-k+1];
                }
            }
            return result;
        }
};

int main(int argc, char* argv[]) {
  vector<double> result =
      AverageOfSubArrayOfSizeK::findAverage(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  cout << "Averages of subarrays of size K: ";
  for (double d : result) {
    cout << d << " ";
  }
  cout << endl;
  return 0;
}