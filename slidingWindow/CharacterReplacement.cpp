/*
Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter, 
find the length of the longest substring having the same letters after replacement.

Example 1:

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".
Example 2:

Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have the longest repeating substring "bbbb".
Example 3:

Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength{0},maxRepeatCharLenWin{0},winLen{0};
    unordered_map<char,int> mp;
    for(int wStart{0},wEnd{0}; wEnd < str.size(); wEnd++){
        // Dynamic Sliding window
        // Update the char frequency
        mp[str[wEnd]]++;
        // update the max Repeating character in the window frequency
        maxRepeatCharLenWin = max(mp[str[wEnd]],maxRepeatCharLenWin);
        winLen = wEnd-wStart+1;
        while(winLen - maxRepeatCharLenWin > k){
            // shrink the window
            mp[str[wStart]]--;
            wStart++;
        }
        // We can replace the characters in the substring
        maxLength = max(maxLength,winLen);
    }
    return maxLength;
  }
};
