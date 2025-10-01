class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>> (
                m, 
                vector<int> (2, -1)
            )
        );
        int mod = 1e9 + 7;
        function<int(int,int,int)> helper = [&](int i, int j, int dir) -> int {
            if(i == n - 1 && j == m - 1) return 1;
            if(i > n - 1 || j > m - 1) return 0;
            if(dp[i][j][dir] != -1) return dp[i][j][dir];
            if(grid[i][j] == 1) {
                if(dir == 0) return dp[i][j][dir] = helper(i + 1, j, 1);
                else return dp[i][j][dir] = helper(i , j + 1, 0);
            }
            return dp[i][j][dir] = (helper(i, j + 1, 0) + helper(i + 1, j, 1)) % mod;
        };
        return helper(0, 0, 0);
    }
};