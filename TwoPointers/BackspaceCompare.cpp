/*
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
Example 2:

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
Example 3:

Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x" respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
Example 4:

Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
*/

#include <iostream>
#include <string>
using namespace std;

class BackspaceCompare {
 public:
  static bool compare(const string &str1, const string &str2) {
    int lPtr = str1.size() - 1;
    int rPtr = str2.size() - 1;
    int lSkip{0},rSkip{0};
    while(lPtr >= 0 && rPtr >= 0){
        while(str1[lPtr] == '#'){
            lSkip++;
            lPtr--;
        }
        if(lSkip){
            lPtr = lPtr - lSkip;
            lSkip = 0;
        }
        while(str2[rPtr] == '#'){
            rSkip++;
            rPtr--;
        }
        if(rSkip){
            rPtr = rPtr - rSkip;
            rSkip = 0;
        }

        if(lPtr < 0 && rPtr < 0){ // reached end of both the strings
            return true;
        }

        if(lPtr < 0 || rPtr < 0){ // reached end of one of the strings
            return false;
        }
        
        if(str1[lPtr--] != str2[rPtr--]){            
            return false;
        }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}