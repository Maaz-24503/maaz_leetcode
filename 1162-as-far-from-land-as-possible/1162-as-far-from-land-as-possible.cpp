class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        queue<vector<int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({0, i, j});
                }
            }
        }

        function<bool(int, int)> isValidWater = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0;
        };

        vector<vector<int>> d{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            int currDist = curr[0], curri = curr[1], currj = curr[2];
            for(int k = 0; k < 4; k++){
                int ni = curri + d[k][0], nj = currj + d[k][1];
                if(isValidWater(ni, nj)){
                    if(1 + currDist < dist[ni][nj]){
                        dist[ni][nj] = 1 + currDist;
                        q.push({1 + currDist, ni, nj});
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, *max_element(dist[i].begin(), dist[i].end()));
        }

        return ans == 0 || ans == INT_MAX ? -1 : ans;
    }
};