class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int mini = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(i == n - 1){
                        if(k != j) mini = min(mini, grid[i][k]);
                    } else {
                        if(k != j) mini = min(mini, grid[i][k] + dp[i + 1][k]);
                    }
                }
                dp[i][j] = mini;
            }
        }
        return n == 1 ? grid[0][0] : *min_element(dp[0].begin(), dp[0].end());
    }
};