class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool> (m, false));
        vector<vector<bool>> atlantic(n, vector<bool> (m, false));
        vector<vector<int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        function<void(int, int, vector<vector<bool>> &)> dfs = [&](int i, int j, vector<vector<bool>> &isVisited) -> void {
            isVisited[i][j] = true;
            for(int k = 0; k<4; k++){
                int ni = d[k][0] + i, nj = d[k][1] + j;
                if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;
                if(isVisited[ni][nj]) continue;
                if(heights[ni][nj] >= heights[i][j]) dfs(ni, nj, isVisited);
            }
        };
        for(int i = 0; i<m; i++) dfs(0, i, pacific);
        for(int i = 0; i<n; i++) dfs(i, 0, pacific);
        for(int i = 0; i<n; i++) dfs(i, m - 1, atlantic);
        for(int i = 0; i<m; i++) dfs(n - 1, i, atlantic);
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
        return ans;
    }
};