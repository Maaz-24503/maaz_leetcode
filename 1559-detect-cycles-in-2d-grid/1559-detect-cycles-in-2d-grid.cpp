class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> isVisited(n, vector<bool> (m, false));
        vector<vector<int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        map<int, int> moveMap{{-1, 4}, {0, 1}, {1, 0}, {2, 3}, {3, 2}};
        
        function<bool(int, int)> isValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        function<bool(int, int, int)> dfs = [&](int i, int j, int prevMove) -> bool {
            if(isVisited[i][j]) return false;
            isVisited[i][j] = true;
            for(int k = 0; k < 4; k++){
                int ni = i + d[k][0], nj = j + d[k][1];
                if(k == moveMap[prevMove] || !isValid(ni, nj) || grid[i][j] != grid[ni][nj]) continue;
                if(isVisited[ni][nj]) return true;
                if(dfs(ni, nj, k)) return true;
            }
            return false;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i, j, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};