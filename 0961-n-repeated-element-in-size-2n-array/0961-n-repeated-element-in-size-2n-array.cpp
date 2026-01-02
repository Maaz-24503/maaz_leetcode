class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 3; i++)
            if(nums[i] == nums[i + 1] || nums[i] == nums[i + 2] || nums[i] == nums[i + 3]) 
                return nums[i];
            else if(nums[i + 3] == nums[i + 2] || nums[i + 1] == nums[i + 3]) 
                return nums[i + 3];
            else if(nums[i + 1] == nums[i + 2])
                return nums[i + 2];
        return -1;
    }
};