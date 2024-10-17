class Solution {
public:
    void fill(vector<vector<char>>& board, int i, int j){
        if(board[i][j] != '.') return;
        board[i][j] = 'O';

        if(i>0) fill(board, i-1, j);
        if(i<board.size()-1) fill(board, i+1, j);
        if(j>0) fill(board, i, j-1);
        if(j<board[0].size()-1) fill(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i<board.size(); i++)
            for(int j = 0; j<board[i].size(); j++)
                if(board[i][j] == 'O') board[i][j] = '.';
        for(int i = 0; i<board[0].size(); i++){
            if(board[0][i] == '.') fill(board, 0, i);
            if(board[board.size()-1][i] == '.') fill(board, board.size()-1, i);
        }
        for(int i = 0; i<board.size(); i++){
            if(board[i][0] == '.') fill(board, i, 0);
            if(board[i][board[0].size()-1] == '.') fill(board, i, board[0].size()-1);
        }
        for(int i = 0; i<board.size(); i++)
            for(int j = 0; j<board[i].size(); j++)
                if(board[i][j] != 'O') board[i][j] = 'X';
    }
};