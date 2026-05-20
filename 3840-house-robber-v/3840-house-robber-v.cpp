class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
            dp[i] = colors[i] == colors[i + 1] ? max(nums[i] + dp[i + 2], dp[i + 1]) : nums[i] + dp[i + 1];
        return dp[0];
    }
};