class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size(), m = toppingCosts.size();
        vector<vector<int>> dp(m + 1, vector<int>(target + 1, -1));
        function<int(int,int)> helper = [&](int i, int j) -> int {
            if(j > target) return j - target;
            if(i == m) return dp[i][j] = target - j;
            if(dp[i][j] != -1) return dp[i][j];
            dp[i][j] = helper(i + 1, j); 
            dp[i][j] = min(dp[i][j], helper(i + 1, toppingCosts[i] + j));
            dp[i][j] = min(dp[i][j], helper(i + 1, (2 * toppingCosts[i] + j)));
            return dp[i][j];
        };
        int ans = INT_MAX;
        for(int i = 0; i<n; i++) {
            ans = min(ans, helper(0, baseCosts[i]));
        }
        if(target - ans < 0 || dp[m][target - ans] != ans) return ans + target;
        return target - ans;
    }
};