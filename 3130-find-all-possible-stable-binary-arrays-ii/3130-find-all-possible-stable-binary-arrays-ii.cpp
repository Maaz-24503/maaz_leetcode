class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>> (one + 1, vector<int> (2, -1)));
        for(int i = 0; i <= zero; i++){
            dp[i][0][0] = i > 0 && i <= limit ? 1 : 0;
        }
        for(int i = 0; i <= one; i++){
            dp[0][i][1] = i > 0 && i <= limit ? 1 : 0;
        }
        function<int(int, int, int)> helper = [&](int zeros, int ones, int lastDig) -> int {
            if (zeros < 0 || ones < 0) return 0;
            if (dp[zeros][ones][lastDig] != -1) return dp[zeros][ones][lastDig];
            if (lastDig == 0){
                dp[zeros][ones][lastDig] = (helper(zeros - 1, ones, 0) + helper(zeros - 1, ones, 1)) % MOD;
                dp[zeros][ones][lastDig] = (dp[zeros][ones][lastDig] - helper(zeros-limit-1, ones, 1) + 0LL + MOD) % MOD;
            } else {
                dp[zeros][ones][lastDig] = (helper(zeros, ones - 1, 1) + helper(zeros, ones - 1, 0)) % MOD;
                dp[zeros][ones][lastDig] = (dp[zeros][ones][lastDig] - helper(zeros, ones-limit-1, 0) + 0LL + MOD) % MOD;
            }
            return dp[zeros][ones][lastDig];
        };
        return (0LL + helper(zero, one, 0) + helper(zero, one, 1)) % MOD;
    }
};