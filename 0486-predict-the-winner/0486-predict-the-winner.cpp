class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(2, -1)));
        function<int(int, int, bool)> helper = [&](int i, int j, bool turn) -> int {
            if(dp[i][j][turn] != -1) return dp[i][j][turn];
            if(i == j) return dp[i][j][turn] = turn ? nums[i] : -nums[i];
            if(turn) return dp[i][j][turn] = max(nums[i] + helper(i + 1, j, !turn), nums[j] + helper(i, j - 1, !turn));
            else return dp[i][j][turn] = min(-nums[i] + helper(i + 1, j, !turn), -nums[j] + helper(i, j - 1, !turn));
        };
        return helper(0, n - 1, true) >= 0;
    }
};