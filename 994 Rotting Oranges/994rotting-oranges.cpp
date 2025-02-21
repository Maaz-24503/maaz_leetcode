class Solution {
public:
    vector<vector<int>> d{{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n, m;

    bool isValid(int i, int j){
        return i<n && i>=0 && j<m && j>=0;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        queue<tuple<int, int, int>> bfs;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) if(grid[i][j] == 2) bfs.push({i, j, 0});
        }
        int ans = 0;
        while(!bfs.empty()){
            auto[a, b, f] = bfs.front();
            bfs.pop();
            for(int i = 0; i<4; i++){
                int dx = a + d[i][0], dy = b + d[i][1];
                if(isValid(dx, dy) && grid[dx][dy] == 1){
                    grid[dx][dy] = 2;
                    ans = max(ans, f + 1);
                    bfs.push({dx, dy, f+1});
                }
            }
        }
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) if(grid[i][j] == 1) return -1;
        return ans;
    }
};