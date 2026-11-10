class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        costs.insert(costs.begin(), 0);
        // function<long long (int)> dp = [&](int i) -> long long {
        //     if(i == n) return 0;
        //     if(memo[i] != -1) return memo[i];
        //     long long ans = -1;
        //     ans = dp(i + 1) + costs[i + 1] + 1;
        //     if(i < n - 1) ans = min(ans, dp(i + 2) + costs[i + 2] + 4);
        //     if(i < n - 2) ans = min(ans, dp(i + 3) + costs[i + 3] + 9);
        //     return memo[i] = ans;
        // };
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            dp[i] = dp[i + 1] + 1 + costs[i + 1];
            if(i < n - 1) dp[i] = min(dp[i], dp[i + 2] + costs[i + 2] + 4);
            if(i < n - 2) dp[i] = min(dp[i], dp[i + 3] + costs[i + 3] + 9);
        }
        return dp[0];
    }
};