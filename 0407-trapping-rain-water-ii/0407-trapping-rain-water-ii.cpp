class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty()) return 0;
        
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Add all boundary cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int water = 0;
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int h = curr[0], x = curr[1], y = curr[2];
            
            for(auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    water += max(0, h - heightMap[nx][ny]);
                    pq.push({max(h, heightMap[nx][ny]), nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        return water;
    }
};