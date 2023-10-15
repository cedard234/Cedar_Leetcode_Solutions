#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:

    vector<int> direction {-1,0,1,0,-1};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]) max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>> & grid, int x, int y){
        if (grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        int area = 1, vertical, horizontal;
        for(int k = 0; k < 4; k++){
            vertical = x + direction[k];
            horizontal = y + direction[k+1];
            if (vertical >= 0 && vertical < grid.size() && horizontal >= 0 && horizontal < grid[0].size()){
                area += dfs(grid, vertical, horizontal);
            }
        }
        return area;
    }
};

int main(){
    vector<vector<int>> grid {{1,1,1,1,1},{1,1,0,1,1},{0,0,0,1,1},{0,0,0,1,1}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}