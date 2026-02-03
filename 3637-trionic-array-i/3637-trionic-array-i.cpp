class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0, n = nums.size();
        if(n < 3 || nums[0] >= nums[1] || nums[n - 2] >= nums[n - 1]) return false;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]) return false;
            if(state == 0){
                if(nums[i] <= nums[i - 1]) state++;
            } else if(state == 1){
                if(nums[i] >= nums[i - 1]) state++;
            } else {
                if(nums[i] <= nums[i - 1]) return false;
            }
        }
        return state == 2;
    }
};