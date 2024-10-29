class Solution {
public:
    // int helper(int i, int j, string s, vector<vector<int>>& memo){
    //     if(i>=j) return 0;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     if(s[i] == s[j]) return memo[i][j] = helper(i+1, j-1, s, memo);
    //     else return memo[i][j] = 1 + min(helper(i+1, j, s, memo), helper(i, j-1, s, memo));
    // }
    int minInsertions(string s) {
        vector<vector<int>> memo(s.size()+1, vector<int>(s.size()+1, 0));
        
        for(int i = s.size(); i>=0; i--){
            for(int j = i+1; j<s.size(); j++){
                if(s[i] == s[j]) memo[i][j] = memo[i+1][j-1];
                else memo[i][j] = 1 + min(memo[i+1][j], memo[i][j-1]);
            }
        }
        return memo[0][s.size()-1];
    }
};