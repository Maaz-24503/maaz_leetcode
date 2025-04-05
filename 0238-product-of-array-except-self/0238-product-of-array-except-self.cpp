class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodRight(n, 1), ans(n);
        int prodLeft = 1;
        for(int i = n-2; i >= 0; i--) prodRight[i] = prodRight[i+1] * nums[i+1];
        for(int i = 0; i<n; i++) {
            ans[i] = prodRight[i] * prodLeft;
            prodLeft *= nums[i];
        }
        return ans;
    }
};