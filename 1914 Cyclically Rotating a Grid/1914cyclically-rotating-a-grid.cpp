class Solution {
public:
    void rotateLayerOnce(vector<vector<int>>& grid, int layer) {
        // cout<<layer<<endl;
        int firstElem = grid[layer][layer];
        for (int i = layer; i < grid[0].size() - layer - 1; i++) {
            grid[layer][i] = grid[layer][i + 1];
        }

        for (int i = layer; i < grid.size() - layer - 1; i++) {
            grid[i][grid[0].size() - layer - 1] =
                grid[i + 1][grid[0].size() - layer - 1];
        }

        for (int i = grid[0].size() - layer - 1; i > layer; i--) {
            grid[grid.size() - layer - 1][i] =
                grid[grid.size() - layer - 1][i - 1];
        }

        for (int i = grid.size() - layer - 1; i > layer + 1; i--) {
            grid[i][layer] = grid[i - 1][layer];
        }
        grid[layer + 1][layer] = firstElem;
    }
    void helper(vector<vector<int>>& grid, int k, int i) {
        int m = grid.size();
        int n = grid[0].size();
        int lim = min(m, n);
        if (i >= lim / 2)
            return;
        int total = 2 * (n - (2 * i)) + 2 * (m - (2 * i) - 2);
        int rot = k % total;
        for (int j = 0; j < rot; j++) {
            rotateLayerOnce(grid, i);
        }
        helper(grid, k, i + 1);
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans = grid;
        helper(ans, k, 0);
        return ans;
    }
};