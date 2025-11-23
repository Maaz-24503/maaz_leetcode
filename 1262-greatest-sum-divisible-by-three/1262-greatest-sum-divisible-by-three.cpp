class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(3, vector<int> (n + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(j == n) return i == 0 ? 0 : INT_MIN;
            if(memo[i][j] != -1) return memo[i][j];
            int take = dp((3 + i - (nums[j] % 3)) % 3, j + 1);
            if(take == INT_MIN) return dp(i, j + 1);
            return memo[i][j] = max(nums[j] + take, dp(i, j + 1));
        };
        return dp(0, 0);
    }
};