class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            int ind = i + 1;
            if(n % ind == 0) ans += nums[i] * nums[i];
        }
        return ans;
    }
};