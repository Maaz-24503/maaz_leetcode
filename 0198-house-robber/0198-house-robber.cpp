class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int a1 = nums[n - 1], a0 = max(nums[n - 1], nums[n - 2]);
        for(int i = n-3; i>=0; i--){
            int temp = a0;
            a0 = max(nums[i] + a1, a0);
            a1 = temp; 
        }        
        return max(a0, a1);
    }
};