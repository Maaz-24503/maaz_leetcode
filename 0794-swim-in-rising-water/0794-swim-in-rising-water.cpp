class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> bfs;
        vector<vector<bool>> isVisited(n, vector<bool> (n, false));
        vector<vector<int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        function<bool(int, int)> isValid = [&](int i, int j) -> bool {
            return i >= 0 && i < n && j >= 0 && j < n && !isVisited[i][j];
        };
        bfs.push({grid[0][0], 0, 0});
        isVisited[0][0] = true;
        while(!bfs.empty()){
            vector<int> curr = bfs.top();
            bfs.pop();
            if(curr[1] == n - 1 && curr[2] == n - 1) return curr[0];
            int t = curr[0], y = curr[1], x = curr[2];
            for(int i = 0; i<4; i++){
                int ny = d[i][0] + y, nx = d[i][1] + x;
                if(isValid(ny, nx)){
                    isVisited[ny][nx] = true;
                    int nt = max(t, grid[ny][nx]);
                    bfs.push({nt, ny, nx});
                }
            }
        }
        return -1;
    }
};