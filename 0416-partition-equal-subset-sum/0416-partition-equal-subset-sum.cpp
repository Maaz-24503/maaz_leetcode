class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int &num : nums) sum += num;
        if(sum % 2 == 1) return false;
        int target = sum/2;
        vector<vector<bool>> memo(n + 1, vector<bool> (target + 1, false));
        for(int i = 0; i<n+1; i++) memo[i][0] = true;
        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<=target; j++){
                if(j - nums[i-1] >= 0) memo[i][j] = memo[i-1][j] || memo[i-1][j - nums[i-1]];
                else memo[i][j] = memo[i-1][j];
            }
        }
        return memo[n][target];
    }
};