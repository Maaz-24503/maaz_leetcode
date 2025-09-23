class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        // memo[zeroDist][oneDist][zeroLeft][oneLeft]
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(zero + 1,
                vector<int>(one + 1, -1)
            )
        );

        function<int(bool,int,int)> helper = [&](bool isZero, int zeroLeft, int oneLeft) {
            if (zeroLeft < 0 || oneLeft < 0) return 0;
            if (zeroLeft == 0 && oneLeft == 0) return 1;
            if (dp[isZero][zeroLeft][oneLeft] != -1) return dp[isZero][zeroLeft][oneLeft];
            if (isZero){
                int branch = 0;
                for(int i = 1; i<=limit; i++) 
                    branch = (branch + helper(false, zeroLeft - i, oneLeft)) % mod;
                dp[isZero][zeroLeft][oneLeft] = branch;
            } else {
                int branch = 0;
                for(int i = 1; i<=limit; i++) 
                    branch = (branch + helper(true, zeroLeft, oneLeft - i)) % mod;
                dp[isZero][zeroLeft][oneLeft] = branch;
            }
            return dp[isZero][zeroLeft][oneLeft];
        };

        return (helper(false, zero, one) + helper(true, zero, one)) % mod;
    }
};
