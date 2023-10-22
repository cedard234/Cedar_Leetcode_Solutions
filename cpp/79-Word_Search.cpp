//This algorithm doesn't pass the test.
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> directions {-1,0,1,0,-1};

    bool exist(vector<vector<char>>& board, string word) {
        bool existed = false;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                vector<vector<bool>> has_searched (board.size(), vector<bool>(board[0].size(), false));
                search_word(board, word, has_searched, existed, i, j, 0);
            }
        }
        return existed;
    }


    void search_word(vector<vector<char>>& board, string word, vector<vector<bool>> & has_searched, bool& existed, int i, int j, int k){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return; //if searched this node or coordiantes are out of range, give up;
        if (has_searched[i][j]) return;
        if (board[i][j] == word[k]){
            if (k == word.length()-1){
                existed = true;
                return;
            }
            has_searched[i][j] = true;
            int row, col;
            for (int cnt = 0; cnt < 4; cnt++){
                row = i + directions[cnt];
                col = j + directions[cnt+1];
                search_word(board, word, has_searched, existed, row, col, k+1);
            }
        }
    }
};

int main(){
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCEFSADEESE";
    Solution sol;
    cout << sol.exist(board, word) << endl;
    return 0;
}