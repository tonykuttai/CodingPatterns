// Given a string, find the length of the longest substring in it with no more than K distinct characters.
// Example 1:
// Input: String="araaci", K=2
// Output: 4
// Explanation: The longest substring with no more than '2' distinct characters is "araa".
// Example 2:
// Input: String="araaci", K=1
// Output: 2
// Explanation: The longest substring with no more than '1' distinct characters is "aa".
// Example 3:
// Input: String="cbbebi", K=3
// Output: 5
// Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
// Example 4:
// Input: String="cbbebi", K=10
// Output: 6
// Explanation: The longest substring with no more than '10' distinct characters is "cbbebi".

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    unordered_map<char,int> mp;
    for(int wStart{0},wEnd{0};wEnd < str.size(); wEnd++){
        mp[str[wEnd]]++;
        if(mp.size() <= k){
            maxLength = max(maxLength,wEnd-wStart+1);
        }
        while (mp.size() > k){
            mp[str[wStart]]--;
            if(mp[str[wStart]] == 0){
                mp.erase(str[wStart]);
            }
            wStart++;           
            if (mp.size() <= k){
                maxLength = max(maxLength, wEnd - wStart + 1);
                break;
            }
        }
    }
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}