class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int> (m - k + 1, k == 1 ? 0 : INT_MAX));
        for(int i = 0; i <= n - k; i++){
            for(int j = 0; j <= m - k; j++){
                // top left is (i, j), bottom right will be (i + k - 1, j + k - 1)
                vector<int> curr;
                for(int p = i; p < i + k; p++){
                    for(int q = j; q < j + k; q++){
                        curr.push_back(grid[p][q]);
                    }
                }
                sort(curr.begin(), curr.end());
                for(int t = 1; t < curr.size(); t++) ans[i][j] = curr[t] == curr[t - 1] ? ans[i][j] : min(ans[i][j], curr[t] - curr[t - 1]);
                if(ans[i][j] == INT_MAX) ans[i][j] = 0;
            }
        }
        return ans;
    }
};