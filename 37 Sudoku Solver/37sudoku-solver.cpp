class Solution {
public:

    vector<vector<char>> board;

    bool isValid(int i, int j, char val){
        int boxX = (j/3) * 3;
        int boxY = (i/3) * 3;
        for(int k = boxY; k<boxY+3; k++) 
            for(int q = boxX; q<boxX+3; q++) 
                if(board[k][q] == val) return false;
        for(int t = 0; t<9; t++) if(board[i][t] == val || board[t][j] == val) return false;
        return true;
    }

    bool solver(){
        // bool temp = true;
        // for(int i = 0; i<9; i++){
        //     for(int j = 0; j<9; j++){
        //         if(board[i][j] == '.'){
        //             temp = false;
        //             break;
        //         }
        //     }
        // }
        // if(temp) return true;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int num = 1; num<=9; num++){
                        if(isValid(i, j, num + '0')){
                            board[i][j] = num+'0';
                            if(solver()) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        while(!solver());
        board = this->board;
    }
};