class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0LL;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                sum += grid[i][j];
        unordered_set<long long> seen{0};
        
        // top to bottom
        long long currSum = 0LL;
        if(m == 1) 
            for(int i = 0; i < n; i++){
                currSum += grid[i][0];
                if(i == 0) continue;
                if(currSum - grid[0][0] == sum - currSum || currSum - grid[i][0] == sum - currSum || 2*currSum == sum) return true;
            }
        else 
            for(int i = 0; i < n; i++){
                if(i == 1) seen.insert(grid[0].begin(), grid[0].end());
                for(int j = 0; j < m; j++){
                    currSum += grid[i][j];
                    if(i == 0){
                        seen.insert(grid[i][0]);
                        seen.insert(grid[i][m - 1]);
                    }
                    else seen.insert(grid[i][j]);
                }
                if(seen.find(2 * currSum - sum) != seen.end()) return true;
            }

        // bottom to top
        seen.clear(); seen.insert(0);
        currSum = 0LL;
        if(m == 1)
            for(int i = n - 1; i >= 0; i--){
                currSum += grid[i][0];
                if(i == n - 1 && 2*currSum != sum) continue;
                if(currSum - grid[n-1][0] == sum - currSum || currSum - grid[i][0] == sum - currSum || 2*currSum == sum) return true;
            }
        else
            for(int i = n - 1; i >= 0; i--){
                if(i == n - 2) seen.insert(grid[n - 1].begin(), grid[n - 1].end());
                for(int j = 0; j < m; j++){
                    currSum += grid[i][j];
                    if(i == n - 1){
                        seen.insert(grid[i][0]);
                        seen.insert(grid[i][m - 1]);
                    }
                    else seen.insert(grid[i][j]);
                }
                if(seen.find(2 * currSum - sum) != seen.end()) return true;
            }

        // left to right
        seen.clear(); seen.insert(0);
        currSum = 0LL;
        if(n == 1)
            for(int j = 0; j < m; j++){
                currSum += grid[0][j];
                if(j == 0 && 2*currSum != sum) continue;
                if(currSum - grid[0][0] == sum - currSum || currSum - grid[0][j] == sum - currSum || 2*currSum == sum) return true;
            }
        else
            for(int j = 0; j < m; j++){
                if(j == 1) {
                    for(int i = 0; i < n; i++) seen.insert(grid[i][0]);
                }
                for(int i = 0; i < n; i++){
                    currSum += grid[i][j];
                    if(j == 0){
                        seen.insert(grid[0][j]);
                        seen.insert(grid[n - 1][j]);
                    }
                    else seen.insert(grid[i][j]);
                }
                if(seen.find(2 * currSum - sum) != seen.end()) return true;
            }

        // right to left
        seen.clear(); seen.insert(0);
        currSum = 0LL;
        if(n == 1)
            for(int j = m - 1; j >= 0; j--){
                currSum += grid[0][j];
                if(j == m - 1 && 2*currSum != sum) continue;
                if(currSum - grid[0][m-1] == sum - currSum || currSum - grid[0][j] == sum - currSum || 2*currSum == sum) return true;
            }
        else
            for(int j = m - 1; j >= 0; j--){
                if(j == m - 2) {
                    for(int i = 0; i < n; i++) seen.insert(grid[i][m - 1]);
                }
                for(int i = 0; i < n; i++){
                    currSum += grid[i][j];
                    if(j == m - 1){
                        seen.insert(grid[0][j]);
                        seen.insert(grid[n - 1][j]);
                    }
                    else seen.insert(grid[i][j]);
                }
                if(seen.find(2 * currSum - sum) != seen.end()) return true;
            }

        return false;
    }
};