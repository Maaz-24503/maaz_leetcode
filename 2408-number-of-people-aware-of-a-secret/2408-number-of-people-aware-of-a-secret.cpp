class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        vector<int> dp(n + 1, -1);
        function<int(int)> helper = [&](int i) -> int {
            if(i > n) return 0;
            if(i == n) return 1;
            if(dp[i] != -1) return dp[i];
            long long sum = 0LL;
            for(int k = i + delay; k < i + forget; k++)
                sum = (sum + helper(k)) % mod;
            return dp[i] = static_cast<int>((i + forget) > n ? (sum + 1) % mod : sum);
        };
        return helper(1);
    }
};