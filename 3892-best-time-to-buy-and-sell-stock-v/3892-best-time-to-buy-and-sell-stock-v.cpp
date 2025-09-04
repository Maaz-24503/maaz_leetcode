class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n + 1, 
            vector<vector<long long>> (
                k + 1, 
                vector<long long> (3, -1)
            )
        );
        function<long long(int, int, int)> helper = [&](int i, int j, int state) -> long long {
            if(i >= n) return state == 0 ? 0 : INT_MIN;
            if(j == 0 && state == 0) return 0;
            if(dp[i][j][state] != -1) return dp[i][j][state];
            long long currPrice = prices[i];
            if(state == 0){
                return dp[i][j][state] = max({
                    helper(i + 1, j - 1, 1) - prices[i],
                    currPrice + helper(i + 1, j - 1, 2) ,
                    helper(i + 1, j, 0)
                });
            } else if(state == 1){
                return dp[i][j][state] = max(
                    helper(i + 1, j, state),
                    helper(i + 1, j, 0) + currPrice
                );
            } else {
                return dp[i][j][state] = max(
                    helper(i + 1, j, state),
                    helper(i + 1, j, 0) - currPrice
                );
            }
        };
        return helper(0, k, 0);
    }
};