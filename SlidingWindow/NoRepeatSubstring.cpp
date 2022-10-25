#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
using namespace std;

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = numeric_limits<int>::min();
    unordered_map<char,int> mp;
    mp[str[0]]++;
    for(int wStart{0},wEnd{1}; wEnd < str.size(); wEnd++){
      mp[str[wEnd]]++;
      if(mp[str[wEnd]] > 1){
        // char already present
        while(mp[str[wEnd]] > 1){
            mp[str[wStart]]--;
            if(mp[str[wStart]] == 0){
                mp.erase(str[wStart]);
            }
            wStart++;
        }

      }else{
        maxLength = max(maxLength,wEnd-wStart+1);        
      }

    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}