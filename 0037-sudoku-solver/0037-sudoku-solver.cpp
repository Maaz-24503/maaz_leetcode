class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        function<bool(int, int, char)> checkValid = [&](int i, int j, char val) -> bool {
            int boxX = (j/3) * 3;
            int boxY = (i/3) * 3;
            for(int k = boxY; k<boxY+3; k++) 
                for(int q = boxX; q<boxX+3; q++) 
                    if(board[k][q] == val) return false;
            for(int t = 0; t<9; t++) if(board[i][t] == val || board[t][j] == val) return false;
            return true;
        };

        function<bool()> backTrack = [&]() -> bool {
            for(int i = 0; i<9; i++){
                for(int j = 0; j<9; j++){
                    if(board[i][j] == '.'){
                        for(char guess = '1'; guess <= '9'; guess++){
                            if(checkValid(i, j, guess)){
                                board[i][j] = guess;
                                if(backTrack()) return true;
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        };

        backTrack();
    }
};