class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i<n; i++){
            if(nums[i] == 2) ans[i] = -1;
            else {
                int num = nums[i];
                long long mask = 1;
                while((mask & num) != 0) mask <<= 1;
                long long preMask = ~(mask - 1);
                mask >>= 1;
                mask -= 1;
                int x = static_cast<int> ((preMask & num) | mask);
                ans[i] = x;
            }
        }
        return ans;
    }
};