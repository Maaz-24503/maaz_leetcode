class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        memo[m-1][n-1] = 1;
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i != m-1 || j != n-1){
                    memo[i][j] = memo[i+1][j] + memo[i][j+1];
                }
            }
        }
        return memo[0][0];
    }
};