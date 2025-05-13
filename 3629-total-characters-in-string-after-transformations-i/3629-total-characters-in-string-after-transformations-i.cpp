class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1000000007;
        vector<vector<int>> dp(t+1, vector<int> (26, 0));
        for(char& c: s) dp[0][c - 'a']++;
        for(int i = 1; i<=t; i++){
            for(int j = 0; j<26; j++){
                if(j == 0) dp[i][j] = dp[i - 1][25];
                else if(j == 1) dp[i][j] = (dp[i - 1][25] + dp[i - 1][0]) % mod;
                else dp[i][j] = dp[i - 1][j - 1];
            }
        }
        int ans = 0LL;
        for(int& num : dp[t]) ans = (ans + num) % mod;
        return ans;
    }
};