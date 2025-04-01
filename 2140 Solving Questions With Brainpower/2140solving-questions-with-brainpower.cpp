class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n-1][0];
        for(int i = n-2; i >= 0; i--) 
            dp[i] = questions[i][1] + i + 1 < n ? max(dp[i+1], questions[i][0] + dp[questions[i][1] + i + 1]): max(dp[i+1], questions[i][0] + 0LL);
        return dp[0];
    }
};