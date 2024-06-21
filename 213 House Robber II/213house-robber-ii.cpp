class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> memo(nums.size(), 0);
        for(int i = nums.size()-2; i>=0; i--){
            if(i == nums.size()-2) memo[i] = nums[i];
            else memo[i] = max(nums[i] + memo[i+2], memo[i+1]);
        }
        int first = memo[0];
        for(int i = nums.size()-1; i>0; i--){
            if(i == nums.size()-1) memo[i-1] = nums[i];
            else memo[i-1] = max(nums[i] + memo[i+1], memo[i]);
        }
        return max(memo[0], first);
    }
};