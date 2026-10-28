class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> memo(
            n + 1, vector<vector<int>>(m + 1, vector<int>(1024, -1)));
        
        function<int(int, int, int)> dp = [&](int i, int j, int curr) -> int {
            if(i == n - 1 && j == m - 1) return curr ^ grid[i][j];
            if(memo[i][j][curr] != -1) return memo[i][j][curr];
            int temp = curr ^ grid[i][j];
            int down = INT_MAX, right = INT_MAX;
            if(i < n - 1) down = dp(i + 1, j, temp);
            if(j < m - 1) right = dp(i, j + 1, temp);
            return memo[i][j][curr] = min(down, right);
        };

        return dp(0, 0, 0);
    }
};