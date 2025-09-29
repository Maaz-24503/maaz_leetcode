class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for(int i = n - 2; i>=0; i--){
            for(int j = 0; j<3; j++){
                int ans = INT_MAX;
                if(obstacles[i + 1] == j + 1){
                    if(obstacles[i] - 1 != (j + 1) % 3) ans = 1 + dp[i + 1][(j + 1) % 3];
                    if(obstacles[i] - 1 != (j + 2) % 3) ans = min(ans, 1 + dp[i + 1][(j + 2) % 3]); 
                } else {
                    ans = dp[i + 1][j];
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][1];
    }
};