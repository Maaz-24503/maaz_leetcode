class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> memo(n + 1, vector<int> (n + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(i == j) return 1;
            if(i > j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            if(s[i] == s[j]) return memo[i][j] = min(dp(i + 1, j), dp(i, j - 1));
            if(s[i] == s[i + 1]) return memo[i][j] = dp(i + 1, j);
            if(s[j - 1] == s[j]) return memo[i][j] = dp(i, j - 1);
            int ans = INT_MAX;
            for(int k = i + 1; k <= j; k++){
                ans = min(dp(i, k - 1) + dp(k, j), ans);
            }
            return memo[i][j] = ans;
        };
        return dp(0, n - 1);
    }
};