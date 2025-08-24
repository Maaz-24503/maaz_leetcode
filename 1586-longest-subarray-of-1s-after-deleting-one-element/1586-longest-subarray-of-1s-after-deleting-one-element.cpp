class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), zeros = 0, l = 0, r = -1;
        int ans = 0;
        while(l < n && r < n) {
            while(zeros < 2 && r < n){
                r++;
                if(r == n) {
                    ans = max(ans, r - l - 1);
                    return ans;
                }
                if(nums[r] == 0) zeros++;
            }
            ans = max(ans, r - l + 1 - zeros);
            while(zeros > 1){
                if(nums[l] == 0) zeros--;
                l++;
            }
        }
        return ans;
    }
};