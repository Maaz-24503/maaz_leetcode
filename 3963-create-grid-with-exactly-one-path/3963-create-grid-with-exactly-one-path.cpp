class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> ans(n, string(m, '#'));
        for(int i = 0; i < n; i++) ans[i][0] = '.';
        for(int j = 0; j < m; j++) ans[n - 1][j] = '.';
        return ans;
    }
};