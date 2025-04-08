class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, count = 0, n = nums.size(), maxi = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0) count++;
            while(count>k){
                if(nums[l] == 0) count--;
                l++;
            }
            maxi = max(maxi, i - l + 1);
        }
        return maxi;
    }
};
