class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i<nums.size(); i++) maxi |= nums[i];
        int ans = 0;
        for(long long mask = 0; mask<(1<<nums.size()); mask++){
            int curr = 0;
            for(int i = 0; i<nums.size(); i++){
                if(((1<<i) & mask) != 0) curr |= nums[i];
            }
            if(curr == maxi) ans++;
        }
        return ans;
    }
};