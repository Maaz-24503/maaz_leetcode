class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(), nonZero = 0, xr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]) nonZero++;
            xr ^= nums[i];
        }
        if(!nonZero) return 0;
        return xr ? n : n - 1;
    }
};