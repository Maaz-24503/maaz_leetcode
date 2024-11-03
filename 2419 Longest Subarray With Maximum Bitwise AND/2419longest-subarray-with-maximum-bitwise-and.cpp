class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) maxi = max(maxi, nums[i]);
        int ans = 1;
        int currCount = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == maxi) currCount++;
            else{
                ans = max(ans, currCount);
                currCount = 0;
            }
        }
        ans = max(ans, currCount);
        return ans;
    }
};