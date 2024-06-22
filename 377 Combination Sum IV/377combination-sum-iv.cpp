class Solution {
public:
    int helper(vector<int>& nums, int target, vector<int>& memo){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(memo[target] != -1) return memo[target];
        int ways = 0;
        for(int i = 0; i < nums.size(); i++){
            ways += helper(nums, target - nums[i], memo);
        }
        return memo[target] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(target+1, -1);
        return helper(nums, target, memo);
    }
};