class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> dk;
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        vector<vector<int>> d{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        function<bool(int, int)> isValid = [n, m](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        dk.push({grid[0][0], 0, 0});
        dist[0][0] = 0;
        while(!dk.empty()){
            vector<int> curr = dk.top(); dk.pop();
            int currD = curr[0], i = curr[1], j = curr[2];
            if(i == n && j == m) break;
            for(int k = 0; k < 4; k++){
                int ni = i + d[k][0], nj = j + d[k][1];
                if(!isValid(ni, nj)) continue;
                int nd = currD + grid[ni][nj];
                if(nd < dist[ni][nj]){
                    dist[ni][nj] = nd;
                    dk.push({nd, ni, nj});
                }
            }
        }
        return dist[n - 1][m - 1] < health;
    }
};