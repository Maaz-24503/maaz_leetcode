class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<long long>> memo(grid.size(),
                                       vector<long long>(grid[0].size(), 0));
        memo[grid.size() - 1][grid[0].size() - 1] =
            grid[grid.size() - 1][grid[0].size() - 1];
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i != grid.size() - 1 || j != grid[0].size() - 1) {
                    if (i == grid.size() - 1) {
                        memo[i][j] = grid[i][j] + memo[i][j + 1];
                    } else if (j == grid[0].size() - 1) {
                        memo[i][j] = grid[i][j] + memo[i + 1][j];
                    }
                    else{
                        memo[i][j] = grid[i][j] + min(memo[i + 1][j], memo[i][j + 1]);
                    }
                }
            }
        }
        return memo[0][0];
    }
};