class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        for(int p = 0; p < n * m; p++){
            int i = p / m, j = p % m;
            int pp = (p + k) % (n * m);
            int ii = pp / m, jj = pp % m;
            ans[ii][jj] = grid[i][j]; 
        }
        return ans;
    }
};