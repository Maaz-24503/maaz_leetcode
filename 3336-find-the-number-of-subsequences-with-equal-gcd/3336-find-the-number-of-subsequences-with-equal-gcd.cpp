class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        function<int(int, int)> gcd = [&](int a, int b) -> int {
            if(a % b == 0) return b;
            return gcd(b, a % b);
        };
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (201, vector<int> (201, -1)));
        function<int(int,int,int)> dp = [&](int i, int g1, int g2) -> int {
            if(i == n) return g1 != 0 && g1 == g2;
            if(memo[i][g1][g2] != -1) return memo[i][g1][g2];
            int skip = dp(i + 1, g1, g2);
            int take1 = dp(i + 1, (g1 == 0) ? nums[i] : gcd(g1, nums[i]), g2);
            int take2 = dp(i + 1, g1, (g2 == 0) ? nums[i] : gcd(g2, nums[i]));
            return memo[i][g1][g2] = (((skip + take1) % MOD) + take2) % MOD;
        };
        return dp(0, 0, 0);
    }
};