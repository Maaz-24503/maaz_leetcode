class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        vector<vector<bool>> isVisited(n, vector<bool> (m, false));
        function<bool(int,int)> isValid = [&](int x, int y){
            return x<n && x>=0 && y<m && y>=0 && !isVisited[x][y] && grid[x][y] == 1;
        };
        int count = 0;
        for(int i = 0; i<n; i++) 
            for(int j = 0; j<m; j++) 
                if(grid[i][j] == 1) count++;

        queue<tuple<int, int, int>> bfs;

        for(int i = 0; i<n; i++) 
            for(int j = 0; j<m; j++) 
                if(grid[i][j] == 2){
                    isVisited[i][j] = true;
                    bfs.push({i, j, 0});
                }
        while(!bfs.empty()){
            auto[x, y, t] = bfs.front();
            bfs.pop();
            for(int i = 0; i<4; i++){
                int nx = dx[i] + x, ny = dy[i] + y;
                if(isValid(nx, ny)){
                    isVisited[nx][ny] = true;
                    count--;
                    if(!count) return t+1;
                    bfs.push({nx, ny, t+1});
                }
            }
        }
        return count ? -1 : 0;
    }
};