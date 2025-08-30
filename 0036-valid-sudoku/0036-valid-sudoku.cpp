class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        function<bool(int)> col = [board](int j) -> bool {
            vector<bool> seen(10, false);
            for(int i = 0; i<9; i++) 
                if(board[i][j] != '.'){
                    if(seen[board[i][j] - '0']) return false;
                    else seen[board[i][j] - '0'] = true;
                }
            return true;
        };
        function<bool(int)> row = [board](int i) -> bool {
            vector<bool> seen(10, false);
            for(int j = 0; j<9; j++) 
                if(board[i][j] != '.'){
                    if(seen[board[i][j] - '0']) return false;
                    else seen[board[i][j] - '0'] = true;
                }
            return true;
        };
        function<bool(int, int)> box = [board](int startI, int startJ) -> bool {
            vector<bool> seen(10, 0);
            for(int i = startI; i < startI + 3; i++){
                for(int j = startJ; j < startJ + 3; j++){
                    if(board[i][j] != '.'){
                        if(seen[board[i][j] - '0']) return false;
                        else seen[board[i][j] - '0'] = true;
                    }
                }
            }
            return true;
        };
        for(int i = 0; i<9; i++)
            if(!col(i)) return false;
        for(int i = 0; i<9; i++)
            if(!row(i)) return false;
        for(int i = 0; i<9; i += 3)
            for(int j = 0; j<9; j += 3)
                if(!box(i, j)) return false;
        return true;
    }
};