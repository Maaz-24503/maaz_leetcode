class Solution {
public:
    int bs(int left, int right, vector<int>& nums){
        if(right - left <= 2){
            int mini = INT_MAX;
            for(int i = left; i<=right; i++) mini = min(mini, nums[i]);
            return mini;
        }
        int mid = (left + right) / 2;
        if(nums[mid] > nums[left]) return bs(mid, right, nums);
        else return bs(left, mid, nums);
    }
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        return bs(0, nums.size()-1, nums);
    }
};