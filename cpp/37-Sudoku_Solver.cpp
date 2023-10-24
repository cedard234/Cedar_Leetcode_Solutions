#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<vector<bool>>> entryAllowed (9, vector<vector<bool>>(9, vector<bool>(9, true)));
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                mark(board, entryAllowed, i, j);
            }
        }
        solve(board, entryAllowed, 0, 0);
    }

    void mark(vector<vector<char>>& board, vector<vector<vector<bool>>> entryAllowed, int i, int j){
        if (board[i][j] != '.'){
            entryAllowed[i][j] = vector<bool>(9, false);
            entryAllowed[i][j][board[i][j] - '1'] = true;
            for (int k = 0; k < 9; k++){
                entryAllowed[i][k][board[i][j] - '1'] = false;
                entryAllowed[k][j][board[i][j] - '1'] = false;
            }
            int i0 = i / 3 * 3, j0 = j / 3 * 3;
            for (int k = 0; k < 3; k++){
                for (int l = 0; l < 3; l++){
                    entryAllowed[i0 + k][j0 + l][board[i][j] - '1'] = false;
                }
            }
        }
    }

    void solve(<vector<vector>& board, <vector<vector<vector<bool>>>& entryAllowed, int x, int y){

    }
};