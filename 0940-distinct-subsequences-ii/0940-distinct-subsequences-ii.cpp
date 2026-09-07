class Solution {
public:
    int distinctSubseqII(string s) {
        int ans = 0, MOD = 1e9 + 7;
        vector<int> dp(26, 0);

        for (const char& c : s) {
            char temp = c - 'a';
            int add = (ans - dp[temp] + MOD) % MOD;
            dp[temp] = 1 + ans;
            ans = (dp[temp] + add) % MOD;
        }

        return ans;
    }
};