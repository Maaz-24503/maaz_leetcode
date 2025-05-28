class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp (n, vector<int> (m, 0));
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(matrix[i][j] == '1') dp[i][j] = 1;
        for(int i = 0; i<n; i++)
            for(int j = m - 2; j>=0; j--)
                dp[i][j] = matrix[i][j] == '1' ? dp[i][j + 1] + 1 : 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int mini = INT_MAX;
                for(int k = i; k<n; k++){
                    mini = min(mini, dp[k][j]);
                    ans = max(ans, mini * (k - i + 1));
                }
            }
        }
        return ans;
    }
};