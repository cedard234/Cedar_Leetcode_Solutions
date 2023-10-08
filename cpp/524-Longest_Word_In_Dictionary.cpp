#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string & a, string&b){
            if (a.length() == b.length()){
                return a < b;
            } else {
                return a.length() > b.length();
            }
        });
        int word_index = 0;
        while (word_index < dictionary.size()){
            int letter = 0;
            for(int i = 0; i < s.length(); i++){
                if (s[i] == dictionary[word_index][letter]){
                    letter++;
                }
            }
            if (letter == dictionary[word_index].length()){
                return dictionary[word_index];
            } else{
                word_index++;
            }
        }
        return "";
    }
};


int main (){
    vector<string> dictionary = {"ale","apple","monkey","plea"};
    Solution sol;
    string s = "abpcplea";
    cout << sol.findLongestWord(s,dictionary) << endl;
}