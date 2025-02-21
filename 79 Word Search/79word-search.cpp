class Solution {
public:
    vector<vector<int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> used;
    vector<vector<char>> board;
    int n, m;
    string word;

    bool isValid(int i, int j){
        return i<n && i>=0 && j<m && j>=0;
    }

    bool helper(int i, int j, int k){
        // cout<<k;
        if(k == word.size()) return true;
        for(int t = 0; t<4; t++){
            int i1 = i + d[t][0], j1 = j + d[t][1];
            if(isValid(i1, j1) && board[i1][j1] == word[k] && !used[i1][j1]){
                used[i1][j1] = true;
                if(helper(i1, j1, k+1)) return true;
                used[i1][j1] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        n = board.size();
        m = board[0].size();
        used.resize(n, vector<bool> (m, false));
        this->word = word;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    used[i][j] = true;
                    if(helper(i, j, 1)) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
};