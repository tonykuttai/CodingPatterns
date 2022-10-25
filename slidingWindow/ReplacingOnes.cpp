
#include <iostream>
#include <vector>
using namespace std;

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0, winLen{0};
    vector<int> mp(2,0);
    for(int wStart{0},wEnd{0};wEnd < arr.size();wEnd++){
      mp[arr[wEnd]]++;
      winLen = wEnd-wStart+1;
      while(mp[0] > k){
        // shrink the window
        mp[arr[wStart]]--;
        wStart++;
      }

      maxLength = max(maxLength,wEnd-wStart+1);     

    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}