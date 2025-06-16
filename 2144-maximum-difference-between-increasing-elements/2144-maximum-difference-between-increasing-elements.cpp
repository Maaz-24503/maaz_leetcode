class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0, n = nums.size(), mini = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = max(ans, nums[i] - mini);
            mini = min(mini, nums[i]);
        }
        return ans > 0 ? ans : -1;
    }
};