class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        function<bool(int, int)> isValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] > 0;
        };
        vector<vector<int>> d{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int ans = grid[i][j];
            grid[i][j] = -1;
            for(int p = 0; p < 4; p++){
                int ni = i + d[p][0], nj = j + d[p][1];
                if(isValid(ni, nj)) ans += dfs(ni, nj);
            }
            return ans % k;
        };
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] > 0 && dfs(i, j) == 0) 
                    ans++; 
        return ans;
    }
};