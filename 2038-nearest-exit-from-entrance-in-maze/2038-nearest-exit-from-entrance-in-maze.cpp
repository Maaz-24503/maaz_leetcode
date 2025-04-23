class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        vector<vector<bool>> isVisited(n, vector<bool> (m, false));
        function<bool(int,int)> isValid = [&](int x, int y){
            return x<n && x>=0 && y<m && y>=0 && !isVisited[x][y] && maze[x][y] == '.';
        };
        queue<tuple<int, int, int>> bfs;
        bfs.push({entrance[0], entrance[1], 0});
        isVisited[entrance[0]][entrance[1]] = true;
        while(!bfs.empty()){
            auto[x, y, moves] = bfs.front();
            bfs.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx, ny)){
                    isVisited[nx][ny] = true;
                    if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1) return moves + 1;
                    bfs.push({nx, ny, moves+1});
                }
            }
        }
        return -1;
    }
};