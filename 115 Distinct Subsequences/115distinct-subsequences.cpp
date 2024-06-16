class Solution {
public:
    int helper(string s, string t, int i, int j, vector<vector<int>>& memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(j == t.size()) return memo[i][j] = 1;
        if(i == s.size()) return memo[i][j] = 0;
        if(t.size()-j > s.size()-i) return memo[i][j] = 0;
        if(s[i] == t[j]) return memo[i][j] = helper(s,t,i+1,j+1,memo) + helper(s,t,i+1,j,memo);
        return memo[i][j] = helper(s,t,i+1,j,memo);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size()+1, vector<int>(t.size()+1, -1));
        return helper(s,t,0,0,memo);
    }
};