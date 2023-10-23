#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> boardCaptured (board.size(), vector<char>(board[0].size(), 'X'));
        for (int i = 0; i < board.size(); i++){//search two vertical sides
            dfs(board, boardCaptured, i, 0);
            dfs(board, boardCaptured, i, board[0].size()-1);
        }
        for (int j = 0; j < board[0].size(); j++){
            dfs(board, boardCaptured, 0, j);
            dfs(board, boardCaptured, board.size()-1, j);
        }
        board = boardCaptured;
        return;
    }

    vector<int> directions {-1, 0, 1, 0, -1};

    void dfs(vector<vector<char>>& board, vector<vector<char>>& boardCaptured, int x, int y){
        if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0) return;
        if (board[x][y] == 'X' || boardCaptured[x][y] == 'O') return;
        else{
            boardCaptured[x][y] = 'O';
            for (int k = 0; k < 4; k++){
                dfs(board, boardCaptured, x+directions[k], y+directions[k+1]);
            }
        }
    }
};

int main(){
    vector<vector<char>> board {{'O', 'O'}, {'O', 'O'}};
    Solution sol;
    sol.solve(board);
    return 0;
}