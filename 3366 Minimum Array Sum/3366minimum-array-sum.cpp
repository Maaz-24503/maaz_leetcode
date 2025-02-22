class Solution {
public:
    vector<int> nums;
    int n, k;
    vector<vector<vector<int>>> memo;

    int helper(int i, int op1, int op2){
        if(i == n) return 0;
        if(memo[i][op1][op2] != -1) return memo[i][op1][op2];
        int ans = INT_MAX;
        ans = min(ans, helper(i + 1, op1, op2) + nums[i]);
        if(op1 > 0){
            if(op2 > 0 && ((nums[i]+1)/2) >=k) ans = min(ans, helper(i + 1, op1 - 1, op2 - 1) + ((nums[i]+1)/2) - k);
            ans = min(ans, helper(i+1, op1 - 1, op2) + (nums[i]+1)/2);
        }
        if(op2 > 0 && nums[i] >= k){
            if(op1 > 0) ans = min(ans, helper(i + 1, op1 - 1, op2 - 1) + (nums[i] - k + 1) / 2);
            ans = min(ans, helper(i + 1, op1, op2 - 1) + nums[i] - k);
        }
        return memo[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        this->nums = nums;
        this->k = k;
        n = nums.size();
        memo.resize(n+1, vector<vector<int>>(op1 + 1, vector<int> (op2 + 1, -1)));
        return helper(0, op1, op2);
    }
};