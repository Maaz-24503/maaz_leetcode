class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int maxi = *max_element(arr.begin(), arr.end());
        if(maxi <= 0) return maxi;
        vector<vector<int>> dp(2, vector<int> (n, 0));
        dp[1][0] = arr[0];
        dp[0][0] = max(arr[0], 0);
        for(int i = 1; i<n; i++) {
            dp[1][i] = max(dp[1][i - 1] + arr[i], arr[i]);
            dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
            dp[0][i] = max(dp[0][i], dp[1][i - 1]);
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};