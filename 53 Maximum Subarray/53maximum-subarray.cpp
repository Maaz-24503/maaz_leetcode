class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mini = min(0, nums[0]);
        int sum = nums[0];
        int maxi = nums[0];
        for(int i = 1; i<n; i++){
            sum += nums[i];
            maxi = max(sum - mini, maxi);
            mini = min(mini, sum);
        }
        return maxi;
    }
};