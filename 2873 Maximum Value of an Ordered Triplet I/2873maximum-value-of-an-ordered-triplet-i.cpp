class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxRight(n);
        vector<int> maxLeft(n);
        int maxi = nums[0], maxi2 = nums[n-1];
        for(int i = 1; i<n; i++){
            maxLeft[i] = maxi;
            maxi = max(maxi, nums[i]);
            maxRight[n - i - 1] = maxi2;
            maxi2 = max(maxi2, nums[n - i - 1]);
        }
        long long ans = 0;
        for(int i = 1; i<n-1; i++) ans = max(ans, ((0LL + maxLeft[i] - nums[i]) * maxRight[i]));
        return ans;
    }
};