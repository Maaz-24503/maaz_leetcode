class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> memo(n + 1, vector<int> (m + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(i >= n || j >= m) return INT_MIN;
            if(memo[i][j] != -1) return memo[i][j];
            int take = dp(i + 1, j + 1);
            take = take == INT_MIN ? 0 : take;
            return memo[i][j] = max({nums1[i]*nums2[j] + take, dp(i + 1, j), dp(i, j + 1), nums1[i]*nums2[j]});
        };
        return dp(0, 0);
    }
};