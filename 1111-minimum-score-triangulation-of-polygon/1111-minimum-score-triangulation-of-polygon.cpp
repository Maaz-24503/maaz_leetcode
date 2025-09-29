class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        function<int(int, int)> helper = [&](int i, int j){
            if(abs(i - j) <= 1) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int ans = INT_MAX;
            for(int k = i + 1; k<j; k++)
                ans = min(ans, helper(i, k) + (values[i] * values[k] * values[j]) + helper(k, j));
            return dp[i][j] = ans;
        };
        return helper(0, n - 1);
    }
};