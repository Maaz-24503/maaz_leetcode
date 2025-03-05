class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n < 2) return 0;
        vector<int> dp(n, 0);
        for(int i = 1; i<n; i++){
            if(s[i] == ')'){
                if(s[i-1] == '(') dp[i] = i>1 ? dp[i-2] + 2 : 2;
                else if(s[i-1] == ')'){
                    if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '('){
                        if(i - dp[i - 1] - 2 >= 0){
                            dp[i] = dp[i - 1] + 2 + dp[i - dp[i-1] - 2];
                        }
                        else dp[i] = dp[i-1] + 2;
                    }
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};