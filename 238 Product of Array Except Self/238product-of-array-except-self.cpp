class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nums;
        vector<int> left_prod(n,1);
        vector<int> right_prod(n,1);
        vector<int> ans(n,1);
        int ls, rs = 1;
        for(int i = 1; i<n; i++){
            ls = ls*nums[i-1];
            left_prod[i] = ls;
            rs = rs*nums[n-i];
            right_prod[n-i-1] = rs;
        }
        for(int i = 0; i<n; i++) ans[i] = left_prod[i]*right_prod[i];
        return ans;
    }
};