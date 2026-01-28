class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cost(n, vector<int> (m, INT_MAX));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) cost[i][j] = 0;
                else{ 
                    if(i > 0)
                        cost[i][j] = min(cost[i][j], grid[i][j] + cost[i - 1][j]);
                    if(j > 0)
                        cost[i][j] = min(cost[i][j], grid[i][j] + cost[i][j - 1]);
                }
            }
        }
        for(int t = 0; t < k; t++){
            vector<int> groupBest(1e4 + 1, INT_MAX);
            int maxi = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    int curr = grid[i][j];
                    maxi = max(curr, maxi);
                    groupBest[curr] = min(groupBest[curr], cost[i][j]);
                }
            }
            for(int p = maxi - 1; p >= 0; p--){
                groupBest[p] = min(groupBest[p], groupBest[p + 1]);
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(i == 0 && j == 0) cost[i][j] = 0;
                    else{ 
                        cost[i][j] = groupBest[grid[i][j]];
                        if(i > 0)
                            cost[i][j] = min(cost[i][j], grid[i][j] + cost[i - 1][j]);
                        if(j > 0)
                            cost[i][j] = min(cost[i][j], grid[i][j] + cost[i][j - 1]);
                    }
                }
            }
        }
        return cost[n - 1][m - 1];
    }
};