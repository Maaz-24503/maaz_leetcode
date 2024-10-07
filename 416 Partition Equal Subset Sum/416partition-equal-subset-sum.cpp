class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) sum += nums[i];
        if(sum%2 == 1) return false;
        sum /= 2;
        vector<vector<bool>> memo(nums.size() + 1, vector<bool>(sum + 1, false));
        for(int i = 0; i<nums.size()+1; i++) memo[i][0] = true;
        for(int i = 1; i<nums.size()+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(j - nums[i-1] >= 0) memo[i][j] = memo[i-1][j - nums[i-1]] || memo[i-1][j];
                else memo[i][j] = memo[i-1][j];
            }
        }
        return memo[nums.size()][sum];
    }
};