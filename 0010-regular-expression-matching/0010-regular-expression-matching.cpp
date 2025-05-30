class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> memo(n + 1, vector<int> (m + 1, -1));
        function<int(int, int)> helper = [&](int i, int j){
            if(memo[i][j] != -1) return memo[i][j];
            if(i == n && j == m) return memo[i][j] = 1;
            if(i == n || j == m) {
                if(j < m - 1 && p[j + 1] == '*') return memo[i][j] = helper(i, j + 2);
                return memo[i][j] = 0;
            }
            if(j < m - 1 && p[j + 1] == '*'){
                if(p[j] == '.' || p[j] == s[i]) return memo[i][j] = helper(i + 1, j) || helper(i, j + 2) ;
                else return memo[i][j] = helper(i, j + 2);
            } 
            if(p[j] == '.' || p[j] == s[i]) return memo[i][j] = helper(i + 1, j + 1);
            return memo[i][j] = 0;
        };
        return helper(0, 0);
    }
};