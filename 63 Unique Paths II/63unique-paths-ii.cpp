class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> memo(m+1, vector<long long>(n+1, 0));
        memo[m-1][n-1] = obstacleGrid[m-1][n-1] == 1?0:1;
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i != m-1 || j != n-1){
                    if(obstacleGrid[i][j] == 1) memo[i][j] = 0;
                    else memo[i][j] = memo[i+1][j] + memo[i][j+1];
                }
            }
        }
        return memo[0][0];
    }
};