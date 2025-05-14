class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0LL;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                sum += grid[i][j];

        if(sum % 2) return false;
        long long target = sum/2;

        // Column based search
        long long preSum = 0LL;
        for(int j = 0; j<m-1; j++){
            for(int i = 0; i<n; i++)
                preSum += grid[i][j];
            if(preSum == target) return true;
            if(preSum > target) break;
        }

        // row based search
        preSum = 0LL;
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<m; j++)
                preSum += grid[i][j];
            if(preSum == target) return true;
            if(preSum > target) return false;
        }
        return false;
    }
};