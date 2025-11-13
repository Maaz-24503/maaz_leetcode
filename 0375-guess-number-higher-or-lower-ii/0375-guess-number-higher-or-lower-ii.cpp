class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int> (n + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(i >= j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INT_MAX;
            for(int k = i; k<=j; k++){
                ans = min(ans, k + max(dp(i, k - 1), dp(k + 1, j)));
            }
            return memo[i][j] = ans;
        };
        return dp(1, n);
    }
};