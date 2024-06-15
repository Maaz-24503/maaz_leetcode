class Solution {
public:
    bool helper(string& s1, string& s2, string& s3, vector<vector<int>>& memo, int i, int j) {
        if (i + j == s3.length()) {
            return true;
        }
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }
        bool ans = false;
        if (i < s1.length() && s1[i] == s3[i + j]) {
            ans = helper(s1, s2, s3, memo, i + 1, j);
        }
        if (!ans && j < s2.length() && s2[j] == s3[i + j]) {
            ans = helper(s1, s2, s3, memo, i, j + 1);
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n1 + n2 != n3) {
            return false;
        }
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));
        return helper(s1, s2, s3, memo, 0, 0);
    }
};
