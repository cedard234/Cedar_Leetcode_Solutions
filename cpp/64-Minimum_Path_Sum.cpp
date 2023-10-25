#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         return findMin(grid, grid.size()-1, grid[0].size()-1);
//     }

//     int findMin(vector<vector<int>>& grid, int x, int y){
//         if (x == 0 && y == 0) return grid[x][y];
//         else if (x == 0) return grid[x][y] + findMin(grid,x,y-1);
//         else if (y == 0) return grid[x][y] + findMin(grid,x-1,y);
//         else{
//             return grid[x][y] + min(findMin(grid,x,y-1), findMin(grid, x-1,y));
//         }
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==1){
            int sum = 0;
            for (int i = 0; i < grid[0].size(); i++){
                sum += grid[0][i];
            }
            return sum;
        }
        vector<vector<int>> minPath(grid.size(), vector<int>(grid[0].size()));
        minPath[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); i++){
            minPath[i][0] = grid[i][0] + minPath[i-1][0];
        }
        for (int j = 1; j < grid[0].size(); j++){
            minPath[0][j] = grid[0][j] + minPath[0][j-1];
        }

        for (int i = 1; i< grid.size(); i++){
            for (int j = 1; j < grid[0].size(); j++){
                minPath[i][j] = grid[i][j] + min(minPath[i-1][j], minPath[i][j-1]);
            }
        }
        return minPath[grid.size()-1][grid[0].size()-1];
    }

};

int main(){
    vector<vector<int>> grid {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    cout << sol.minPathSum(grid) << endl;
    return 0;
}