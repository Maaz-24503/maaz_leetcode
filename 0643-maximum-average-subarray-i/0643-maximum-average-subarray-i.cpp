class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<k; i++) sum += nums[i];
        int maxSum = sum;
        for(int i = 0; i<n - k; i++){
            sum += nums[i + k] - nums[i];
            maxSum = max(sum, maxSum);
        }
        return (maxSum * 1.0)/(k * 1.0);
    }
};