class Solution {
public:
    int helper(vector<int>& nums, int target, int i, vector<unordered_map<string, int>>& memo){
        if(memo[i].find(to_string(target)) != memo[i].end()) return memo[i][to_string(target)];
        if(i == nums.size() && target == 0) return 1;
        if(i == nums.size()) return 0;
        return memo[i][to_string(target)] = helper(nums, target-nums[i], i+1, memo)+helper(nums, target+nums[i], i+1, memo);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<string, int>> memo(nums.size()+1);
        return helper(nums, target, 0, memo);
    }
};