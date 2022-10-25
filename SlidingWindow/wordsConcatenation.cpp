/*
Words Concatenation (hard)#
Given a string and a list of words, find all the starting indices of substrings in the given string 
that are a concatenation of all the given words exactly once without any overlapping of words. 
It is given that all words are of the same length.

Example 1:

Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".
Example 2:

Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    vector<int> resultIndices;
    // TODO: Write your code here
    unordered_map<string,int> wordFreqMap;
    for(auto word : words){
        wordFreqMap[word]++;
    }

    int wordsCount = words.size(),wordLength = words[0].length();
    for(int i = 0;i < int(str.size())-(wordsCount*wordLength); i++){
        unordered_map<string,int> wordsSeen;
        for(int j = 0;j < wordsCount;j++){
            int nextWordIndex = i + j * wordLength;
            // get the next word from the string
            string nextword = str.substr(nextWordIndex,wordLength);
            if(wordFreqMap.count(nextword) == 0){
                // word is not present in the array Words
                break; // we dont need this word
            }
            // add the word to the wordsseen map
            wordsSeen[nextword]++;
            if(wordsSeen[nextword] > wordFreqMap[nextword]){
                // no need to process further
                break;
            }
            if(j+1 == wordsCount){
                resultIndices.emplace_back(i);
            }
        }
    }


    return resultIndices;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
