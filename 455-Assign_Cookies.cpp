#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort the children
        sort(s.begin(), s.end()); // sort the cookies
        int i=0, j=0;
        while ( i < g.size() && j < s.size() ){
            if ( s[j] >= g[i] ){
                i++;
            }
            j++;
        }
        return j;
    }
};

int main() {
    Solution sol;
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}