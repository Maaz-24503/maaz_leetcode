class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> preSum = grid;
        for(int j = 0; j < m; j++)
            for(int i = 1; i < n; i++) 
                preSum[i][j] = preSum[i - 1][j] + grid[i][j];
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < m; j++){
                sum += preSum[i][j];
                if(sum > k) break;
                ans++;
            }
        }
        return ans;
    }
};