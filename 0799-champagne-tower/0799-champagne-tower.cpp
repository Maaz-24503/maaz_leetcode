class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1);
        for(int i = 0; i <= query_row; i++)
            dp[i] = vector<double>(i + 1, 0.0);
        dp[0][0] = poured;
        for(int i = 1; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                if(j != 0) dp[i][j] = max(0.0, (dp[i - 1][j - 1] - 1.0) / 2);
                if(j != i) dp[i][j] += max(0.0, (dp[i - 1][j] - 1.0) / 2);
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};