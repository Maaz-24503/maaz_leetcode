class Solution {
private:
    string s;
    vector<vector<int>> memo;

    int helper(int i, int j){
        if(j < i) return 0;
        if(i == j) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        if(s[i] == s[j]) return memo[i][j] = 2 + helper(i+1, j-1);
        return memo[i][j] = max(helper(i+1, j), helper(i, j-1));
    }

public:
    int longestPalindromeSubseq(string s) {
        this->s = s;
        memo.resize(s.size(), vector<int> (s.size(), -1));
        return helper(0, s.size()-1);
    }
};