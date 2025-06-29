class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxi + 1, 0);
        for(int& num : nums) dp[num]++;
        for(int i = 2; i<=maxi; i++) dp[i] = max(dp[i - 1], dp[i - 2] + (dp[i] * i));
        return dp[maxi];
    }
};