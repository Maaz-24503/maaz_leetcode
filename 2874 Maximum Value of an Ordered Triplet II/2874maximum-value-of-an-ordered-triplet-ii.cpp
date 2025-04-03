class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxLeft = 0, maxDiff = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            ans = max(ans, maxDiff * 1LL * nums[i]);
            maxDiff = max(maxLeft - nums[i], maxDiff);
            maxLeft = max(maxLeft, nums[i]);
        }
        return max(ans, 0LL);
    }
};