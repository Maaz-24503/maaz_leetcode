class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long> (m, 0));
        for(int j = 0; j < m; j++) dp[0][j] = points[0][j];
        for(int i = 1; i < n; i++){
            long long curr = dp[i - 1][0];
            for(int j = 0; j < m; j++){
                curr = max(dp[i - 1][j], curr - 1);
                dp[i][j] = points[i][j] + curr;
            }
            curr = 0;
            for(int j = m - 1; j >= 0; j--){
                curr = max(dp[i - 1][j], curr - 1);
                dp[i][j] = max(dp[i][j], points[i][j] + curr);
            }
        }
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};