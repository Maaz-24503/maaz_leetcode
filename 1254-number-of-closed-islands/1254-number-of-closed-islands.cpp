class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> mat = grid;
        vector<vector<int>> d{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size(), m = grid[0].size();
        function<bool(int, int)> isValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if(mat[i][j] == 0) mat[i][j] = 2;
            else return;
            for(int k = 0; k < 4; k++){
                int ni = i + d[k][0], nj = j + d[k][1];
                if(isValid(ni, nj) && mat[ni][nj] == 0) dfs(ni, nj); 
            }
        };
        int ans = 0;
        for(int i = 0; i < n; i++){ 
            dfs(i, 0);
            dfs(i, m - 1);
        }
        for(int j = 1; j < m - 1; j++){
            dfs(0, j);
            dfs(n - 1, j);
        }
        for(int i = 0; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(mat[i][j] == 0){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};