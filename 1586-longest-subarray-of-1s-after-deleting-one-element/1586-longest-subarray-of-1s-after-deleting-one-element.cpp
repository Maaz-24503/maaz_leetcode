class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, maxi = 0, n = nums.size(), count = 0;
        int zero = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                count++;
                if(zero == -1) zero = i;
                else{
                    l = zero + 1;
                    zero = i;
                }
            }
            maxi = max(maxi, i - l);
        }
        return count == n ? 0 : maxi;
    }
};