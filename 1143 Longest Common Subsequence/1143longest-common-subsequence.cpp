class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length()+1, vector<int>(text2.length()+1, 0));
        for(int i = text1.length(); i>=0; i--){
            for(int j = text2.length(); j>=0; j--){
                if(i == text1.length() || j == text2.length()) memo[i][j] = 0;
                else if(text1[i] == text2[j]) memo[i][j] = 1 + memo[i+1][j+1];
                else memo[i][j] = max(memo[i+1][j], memo[i][j+1]);
            }
        }
        return memo[0][0];
    }
};