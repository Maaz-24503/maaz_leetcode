class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (m, vector<int> (m + n + 1, -1)));
        function<bool(int, int, int)> dp = [&](int i, int j, int open) -> bool {
            if(i >= n || j >= m) return false;
            if(grid[i][j] == ')') open--;
            else open++;
            if(open < 0) return false;
            if(i == n - 1 && j == m - 1) return open == 0;
            if(memo[i][j][open] != -1) return memo[i][j][open];
            return memo[i][j][open] = dp(i + 1, j, open) || dp(i, j + 1, open);
        };
        return dp(0, 0, 0);
    }
};