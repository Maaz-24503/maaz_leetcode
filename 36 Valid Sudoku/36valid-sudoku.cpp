class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            unordered_set<int> seen;
            for(int j = 0; j<9; j++){
                if(board[i][j]!='.'){
                    int curr = board[i][j] - '0';
                    if(seen.find(curr) == seen.end()){
                        seen.insert(curr);
                    }
                    else return false;
                }
            }
        }
        for(int i = 0; i<9; i++){
            unordered_set<int> seen;
            for(int j = 0; j<9; j++){
                if(board[j][i]!='.'){
                    int curr = board[j][i] - '0';
                    if(seen.find(curr) == seen.end()){
                        seen.insert(curr);
                    }
                    else return false;
                }
            }
        }

        for(int p = 0; p<9; p+=3){
            for(int q = 0; q<9; q+=3){
                unordered_set<int> seen;
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(board[i+p][j+q] != '.'){
                            int curr = board[i+p][j+q];
                            if(seen.find(curr) == seen.end()){
                                seen.insert(curr);
                            }
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};