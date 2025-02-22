class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i<coins.size(); i++){
            for(int j = 0; j<=amount; j++){
                if(j>=coins[i]) dp[j] = min(dp[j - coins[i]] == INT_MAX ? INT_MAX : (1 + dp[j - coins[i]]), dp[j]);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};