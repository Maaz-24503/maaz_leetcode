class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> memo(n, vector<int> (m, -1));
        function<int(int, int)> dp = [&](int i , int j) -> int {
            if(j == m) return 1;
            if(i == n) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            if(s[i] == t[j]) return memo[i][j] = dp(i + 1, j + 1) + dp(i + 1, j);
            return memo[i][j] = dp(i + 1, j);
        };
        return dp(0, 0);
    }
};