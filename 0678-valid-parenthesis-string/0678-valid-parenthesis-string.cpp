class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int> (n + 1, -1));
        function<bool(int, int)> dp = [&](int i, int open) -> bool {
            if(i == n) return open == 0;
            if(open < 0) return false;
            if(memo[i][open] != -1) return memo[i][open];
            if(s[i] == ')') return memo[i][open] = dp(i + 1, open - 1);
            else if(s[i] == '(') return memo[i][open] = dp(i + 1, open + 1);
            else return memo[i][open] = dp(i + 1, open - 1) || dp(i + 1, open) || dp(i + 1, open + 1);
        };
        return dp(0, 0);
    }
};