/*
Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters, it will have n!permutations.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.
Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.
Example 4:

Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.


*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    // Sliding window approach
    
    // Populate the frequency of the char's in Pattern
    unordered_map<char,int> mp;
    for(auto p: pattern){
        mp[p]++;
    }
    int matched{0};
    for(int wStart{0},wEnd{0};wEnd < str.size();wEnd++){
        if(mp.count(str[wEnd])){
            // character present in the pattern
            mp[str[wEnd]]--;
            if(mp[str[wEnd]] == 0){
                // complete match of a char
                matched++;
            }
        }

        if(matched == mp.size()){
            return true;
        }

        if(wEnd-wStart+1 > pattern.length()){
            //shrink window
            if(mp.count(str[wStart])){
                if(mp[str[wStart]] == 0){
                    matched--;
                }
                mp[str[wStart]]++;               
            }
             wStart++;
        }       

    }

    return false;
  }
};

int main(){
    // string str{"oidbcaf"};
    // string pattern{"abc"};
    // std::cout << boolalpha << StringPermutation::findPermutation(str,pattern) << endl;

    // str = "odicf";
    // pattern = "dc";
    // std::cout << boolalpha << StringPermutation::findPermutation(str,pattern) << endl;

    // str = "odicf";
    // pattern = "dc";
    // std::cout << boolalpha << StringPermutation::findPermutation(str,pattern) << endl;

    string str{"eidboaoo"};
    string pattern{"ab"};
    std::cout << boolalpha << StringPermutation::findPermutation(str,pattern) << endl;
    
    return 0;
}