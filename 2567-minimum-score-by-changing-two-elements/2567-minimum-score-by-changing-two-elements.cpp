class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int f_0_1 = nums[1] - nums[0], f_1_2 = nums[2] - nums[1], b_0_1 = nums[n - 1] - nums[n - 2], b_1_2 = nums[n - 2] - nums[n - 3];
        return nums[n - 1] - nums[0] - max({f_0_1 + f_1_2, f_0_1 + b_0_1, b_0_1 + b_1_2});
    }
};