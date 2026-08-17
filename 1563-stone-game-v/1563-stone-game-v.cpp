class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n, 0);
        preSum[0] = stoneValue[0];
        for(int i = 1; i < n; i++){
            preSum[i] = preSum[i - 1] + stoneValue[i];
        }
        vector<vector<int>> memo(n, vector<int> (n, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(i == j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            for(int k = i; k < j; k++){
                int leftSum = preSum[k] - (i ? preSum[i - 1] : 0);
                int rightSum = preSum[j] - preSum[k];

                if (leftSum <= rightSum) ans = max(ans, leftSum + dp(i, k));
                if (leftSum >= rightSum) ans = max(ans, rightSum + dp(k + 1, j));
            }
            return memo[i][j] = ans;
        };
        return dp(0, n - 1);
    }
};