class Solution {
public:
    int helper(int i, int k, vector<int>& nums, vector<vector<int>>& memo){
        if(k == 1){
            int remaining = 0;
            for(;i<nums.size(); i++) remaining += nums[i];
            return remaining;
        }
        if(i == nums.size()) return 0;
        if(memo[i][k] != -1) return memo[i][k];
        int left = 0;
        int best = INT_MAX;
        for(int j = i+1; j<nums.size()+1; j++){
            left += nums[j-1];
            best = min(best, max(left, helper(j, k-1, nums, memo)));
        }
        return memo[i][k] = best;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];
        vector<vector<int>> memo(nums.size()+1, vector<int>(k+1, -1));
        return helper(0, k, nums, memo);
    }
};