#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> cities (isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++){
            if (!cities[i]){
                dfs(isConnected, i, cities);
                count++;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> & isConnected, int i, vector<bool> & cities){
        for (int j = 0; j < isConnected.size(); j++){
            if (isConnected[i][j] && !cities[j]){
                cities[j] = true;
                dfs(isConnected, j, cities);
            }
        }
    }

};

int main(){
    vector<vector<int>> isConnected {{1,1,0},{1,1,0},{0,0,1}};
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}