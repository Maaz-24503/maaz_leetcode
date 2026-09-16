class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<array<long long,2>>> dp(n + 1, vector<array<long long,2>>(k + 1, {0, 0}));
        dp[n][0][0] = 1;   

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                long long extend = dp[i + 1][j][1];
                long long close  = (j > 0) ? dp[i][j - 1][0] : 0;
                dp[i][j][1] = (extend + close) % MOD;

                long long skip  = dp[i + 1][j][0];
                long long start = dp[i + 1][j][1];
                dp[i][j][0] = (skip + start) % MOD;
            }
        }

        return (int)dp[0][k][0];
    }
};