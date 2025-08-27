class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<vector<int>>>> memo(
            rows, vector<vector<vector<int>>>(
                cols, vector<vector<int>>(
                    4, vector<int>(2, -1))));

        int directions[4][2] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};

        function<int(int,int,int,bool,int)> dfs = [&](int x, int y, int dir, bool canTurn, int target) -> int {
            int nx = x + directions[dir][0];
            int ny = y + directions[dir][1];
            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != target) {
                return 0;
            }
            int& cached = memo[nx][ny][dir][canTurn];
            if (cached != -1) return cached;

            int best = dfs(nx, ny, dir, canTurn, 2 - target);
            if (canTurn) {
                best = max(best, dfs(nx, ny, (dir + 1) % 4, false, 2 - target));
            }
            return cached = best + 1;
        };

        int result = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        result = max(result, dfs(i, j, dir, true, 2) + 1);
                    }
                }
            }
        }
        return result;
    }
};
