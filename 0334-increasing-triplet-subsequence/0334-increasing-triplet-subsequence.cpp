class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini1 = nums[0], mini2 = INT_MAX, n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i] > mini2) return true;
            if(nums[i] < mini2) 
                if(mini1 < nums[i]) mini2 = nums[i];
                else mini1 = nums[i];
        }
        return false;
    }
};