class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> memo (n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, -1)));
        function<int(int, int, int)> dp = [&](int i, int j, int c) -> int {
            if(c < 0) return INT_MIN;
            if(i == n - 1 && j == m - 1) return memo[i][j][c] = grid[i][j];
            if(i > n - 1 || j > m - 1) return INT_MIN;
            if(memo[i][j][c] != -1) return memo[i][j][c];
            int ans = INT_MIN;
            if(i < n - 1) ans = max(ans, dp(i + 1, j, c - (grid[i + 1][j] == 2 ? 1 : grid[i + 1][j])));
            if(j < m - 1) ans = max(ans, dp(i, j + 1, c - (grid[i][j + 1] == 2 ? 1 : grid[i][j + 1])));
            return memo[i][j][c] = (ans == INT_MIN ? INT_MIN : grid[i][j] + ans);
        };
        int ans = dp(0, 0, k); 
        return ans < 0 ? -1 : ans;
    }
};