class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n + 1, vector<int> (m + 1, -1));
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if(memo[i][j] != -1) return memo[i][j];
            if(i >= n) {
                memo[i][j] = 0;
                for(int k = j; k < m; k++) memo[i][j] += s2[k]; 
                return memo[i][j];
            }
            if(j >= m) {
                memo[i][j] = 0;
                for(int k = i; k < n; k++) memo[i][j] += s1[k]; 
                return memo[i][j];
            }
            if(s1[i] == s2[j]) return memo[i][j] = dp(i + 1, j + 1);
            return memo[i][j] = min(s1[i] + dp(i + 1, j), s2[j] + dp(i, j + 1));
        };
        return dp(0, 0);
    }
};