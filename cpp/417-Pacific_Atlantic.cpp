#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<int> direction{-1,0,1,0,-1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int row = heights.size();
        int column = heights[0].size();
        vector<vector<int>> answer;
        vector<vector<bool>> canFlowToAtlantic (row, vector<bool>(column, false));
        vector<vector<bool>> canFlowToPacific (row, vector<bool>(column, false));
        for (int i = 0; i < row; i++){
            dfs(heights, canFlowToAtlantic, i, column-1);
            dfs(heights, canFlowToPacific, i, 0);
        }
        for (int i = 0; i < column; i++){
            dfs(heights, canFlowToAtlantic, row-1, i);
            dfs(heights, canFlowToPacific, 0, i);
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if (canFlowToAtlantic[i][j] && canFlowToPacific[i][j]){
                    answer.push_back({i,j});
                }
            }
        }
        return answer;
    }

    void dfs(vector<vector<int>> & heights, vector<vector<bool>> & canFlowTo, int row_index, int column_index){
        if (canFlowTo[row_index][column_index]) return;
        else{
            canFlowTo[row_index][column_index] = true;
            int horizontal, vertical;
            for (int k = 0; k < 5; k++){
                horizontal = column_index + direction[k];
                vertical =  row_index + direction[k+1];
                if (horizontal >= 0 && horizontal < heights[0].size() && vertical >= 0 && vertical < heights.size()){
                    if (heights[vertical][horizontal] >= heights[row_index][column_index]){
                        dfs(heights, canFlowTo, vertical, horizontal);
                    }
                }
            }
            // return;
        }
    }
};

int main(){
    vector<vector<int>> heights {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution sol;
    vector<vector<int>> points = sol.pacificAtlantic(heights);
    return 0;
}