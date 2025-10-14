class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(2 * k > n) return false;
        for(int i = 0; i <= n - (2 * k); i++){
            bool valid = true;
            for(int j = i; j < i + k - 1; j++) 
                if(nums[j] >= nums[j + 1]){
                    valid = false;
                    break;
                }
            if(!valid) continue;
            for(int j = i + k; j < i + (2*k) - 1; j++) 
                if(nums[j] >= nums[j + 1]){
                    valid = false;
                    break;
                }
            if(valid) return true;
        }
        return false;
    }
};