class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long ans = LLONG_MIN;
            long long take = 0;
            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                ans = max(ans, take - dp[i + k + 1]);
            }
            dp[i] = ans;
        }
        long long ans = dp[0];
        if (ans == 0) return "Tie";
        return ans > 0 ? "Alice" : "Bob";
    }
};