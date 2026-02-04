class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long MIN = -(1LL<<50);
        vector<vector<long long>> dp(n, vector<long long>(4, MIN));
        
        dp[n-1][3] = nums[n-1];
        
        for(int i = n - 2; i >= 0; i--) {
            // State 0
            long long pick = dp[i + 1][1];
            if(pick == MIN) dp[i][0] = dp[i + 1][0];
            else if(nums[i + 1] > nums[i]) dp[i][0] = max(nums[i] + pick, dp[i + 1][0]);
            else dp[i][0] = dp[i + 1][0];
            
            // State 1
            long long pick1 = MIN;
            if(nums[i + 1] == nums[i]) dp[i][1] = MIN;
            else if(nums[i + 1] > nums[i]) pick1 = dp[i + 1][1];
            else pick1 = dp[i + 1][2];
            if(pick1 != MIN) dp[i][1] = pick1 + nums[i];
            
            // State 2
            long long pick2 = MIN;
            if(nums[i + 1] == nums[i]) dp[i][2] = MIN;
            else if(nums[i + 1] < nums[i]) pick2 = dp[i + 1][2];
            else pick2 = dp[i + 1][3];
            if(pick2 != MIN) dp[i][2] = pick2 + nums[i];
            
            // State 3
            if(nums[i + 1] > nums[i]) dp[i][3] = max(nums[i] + dp[i + 1][3], nums[i] + 0LL);
            else dp[i][3] = nums[i];
        }
        
        return dp[0][0];
    }
};