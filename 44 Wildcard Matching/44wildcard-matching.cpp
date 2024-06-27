class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> memo(n+1, vector<bool>(m+1, false));
        memo[n][m] = true;
        for(int i = n; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i == n){ 
                    if(p[j] == '*') memo[i][j] = memo[i][j+1];
                }
                else if(p[j] == '?' || p[j] == s[i])
                    memo[i][j] = memo[i+1][j+1];
                else if(p[j] == '*')
                    memo[i][j] = memo[i+1][j] || memo[i][j+1];
            }
        }
        return memo[0][0];
    }
};