#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board (n, string(n, '.'));
        vector<bool> column (n, false);
        vector<bool> l_diag (2*n-1, false);
        vector<bool> r_diag (2*n-1, false);
        ans = search(ans, board, column, l_diag, r_diag, 0, n);
        return ans;
    }

    void search(vector<vector<string>>& ans, vector<string>& board, vector<bool>& column, vector<bool>& l_diag, vector<bool>& r_diag, int row, int n){
        if (row == n) ans.push_back(board);
        else {
            for (int i = 0; i < n; i++){
                if (column[i] || l_diag[n-row+i-1] || r_diag[row+i]) continue;
                board[row][i] = 'Q';
                column[i] = true;
                l_diag[n-row+i-1] = true;
                r_diag[row+i] = true;
                search(ans, board, column, l_diag,r_diag,row+1, n);
                board[row][i] = '.';
                column[i] = l_diag[n-row+i-1] = r_diag[row+i] = false;
            }
        }
    }
};