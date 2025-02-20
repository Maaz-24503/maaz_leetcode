class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        if(nums.size() > 1 && nums[0] == 0) return false;
        for(int i = 1; i+1<n; i++){
            maxi--;
            maxi = max(maxi, nums[i]);
            if(maxi == 0) return false;
        }
        return true;
    }
};