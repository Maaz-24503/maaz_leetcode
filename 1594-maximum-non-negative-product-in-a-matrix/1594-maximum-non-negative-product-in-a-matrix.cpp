class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), MOD = 1e9 + 7;
        vector<vector<long long>> dpMin(n, vector<long long> (m, -1));
        vector<vector<long long>> dpMax(n, vector<long long> (m, -1));
        dpMin[n - 1][m - 1] = dpMax[n - 1][m - 1] = grid[n - 1][m - 1];

        for(int i = n - 2; i >= 0; i--) dpMin[i][m - 1] = dpMax[i][m - 1] = dpMin[i + 1][m - 1] * grid[i][m - 1];
        for(int i = m - 2; i >= 0; i--) dpMin[n - 1][i] = dpMax[n - 1][i] = dpMin[n - 1][i + 1] * grid[n - 1][i];
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 2; j >= 0; j--){
                if(grid[i][j] >= 0) {
                    dpMax[i][j] = max(dpMax[i][j + 1], dpMax[i + 1][j]) * grid[i][j];
                    dpMin[i][j] = min(dpMin[i][j + 1], dpMin[i + 1][j]) * grid[i][j];
                } else {
                    dpMin[i][j] = max(dpMax[i][j + 1], dpMax[i + 1][j]) * grid[i][j];
                    dpMax[i][j] = min(dpMin[i][j + 1], dpMin[i + 1][j]) * grid[i][j];
                }
            }
        }
        return dpMax[0][0] >= 0 ? dpMax[0][0] % MOD : -1;
    }
};