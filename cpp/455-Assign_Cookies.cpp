#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end()); // sort the childrenren
        sort(cookies.begin(), cookies.end()); // sort the cookiess
        int child=0, cookie=0;
        while ( child < children.size() && cookie < cookies.size() ){
            if ( cookies[cookie] >= children[child] ){
               child++;
            }
            cookie++;
        }
        return child;
    }
};

int main() {
    Solution sol;
    vector<int> children{1,2,3};
    vector<int> cookies{1,1};
    cout << sol.findContentChildren(children, cookies) << endl;
    return 0;
}