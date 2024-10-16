class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = nums[0];
        int mini = INT_MAX;
        while(r<nums.size()){
            if(l == r){
                if(sum>=target) return 1;
                else{ 
                    r++;
                    if(r<nums.size()) sum += nums[r];
                }
            }
            else if(sum<target){
                r++;
                if(r<nums.size()) sum += nums[r];
            }
            else{
                mini = min(mini, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};