class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 1;
        for(int i = 0; i<n; i++){
            int currSum = nums[i] + nums[n - i - 1];
            ans = max(currSum, ans);
        }
        return ans;
    }
};