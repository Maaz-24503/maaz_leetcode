class Solution {
private:
    vector<vector<vector<int>>> memo;
    int n, m;

    int helper(int i, int j, int moves){
        if(i < 0 || i >= n || j < 0 || j >= m) return 1;
        if(moves == 0) return 0;
        if(memo[i][j][moves] != -1) return memo[i][j][moves];
        return memo[i][j][moves] = (((((helper(i+1, j, moves - 1) + helper(i, j+1, moves - 1)) % 1000000007) + helper(i-1, j, moves-1)) % 1000000007) + helper(i, j-1, moves - 1)) % 1000000007;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (maxMove + 1, -1)));
        this->n = n;
        this->m = m;
        return helper(startColumn, startRow, maxMove);
    }
};