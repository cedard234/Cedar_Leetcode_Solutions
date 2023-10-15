#include<algorithm>
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
    vector<int> direction {-1,0,1,0,-1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), column = row?grid[0].size():0, area = 0, localarea, local_i, local_j;
        for (int i = 0; i < row ; i++){
            for (int j = 0; j < column; j++){
                if (grid[i][j]){
                    localarea = 1;
                    grid[i][j] = 0;
                    stack<pair<int,int>> node;
                    node.push({i,j});
                    while(!node.empty()){
                        auto [center_i, center_j] = node.top();
                        node.pop();
                        for (int k = 0; k < 4 ; k++){
                            local_i = center_i + this->direction[k];
                            local_j = center_j + this->direction[k+1];
                            if (local_i >= 0 && local_i < row && local_j >= 0 && local_j < column && grid[local_i][local_j]){
                                grid[local_i][local_j] = 0;
                                localarea++;
                                node.push({local_i,local_j});
                            }
                        }
                    }
                    area = max(area, localarea);
                }
            }
        }
        return area;
    }
};

int main(){
    vector<vector<int>> grid {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}