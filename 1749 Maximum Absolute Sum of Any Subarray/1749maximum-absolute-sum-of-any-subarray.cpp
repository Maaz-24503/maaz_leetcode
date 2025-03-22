class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0, negSum = 0, posSum = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            if(posSum < 0) posSum = nums[i];
            else posSum += nums[i];
            if(negSum > 0) negSum = nums[i];
            else negSum += nums[i];
            ans = max({ans, -negSum, posSum});
        }
        return ans;
    }
};