#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    //check substring is palindrome or not
    bool check(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
         int j=s.length()-1;
       
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                bool a=check(s,i,j-1);
                bool b=check(s,i+1,j);
//return using bitwise or
                return a || b;
            }
        
        }
        return true;
    }
};

int main(){
    string s = "lcupuuffuupucul";
    Solution sol;
    cout << sol.validPalindrome(s) <<endl;
    return 0;
}