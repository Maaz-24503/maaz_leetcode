class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> preRow(n, 0);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) sum += grid[i][j];
            preRow[i] = sum; 
        }
        if(sum % 2) return false;
        vector<long long> preCol(m, 0);
        long long currSum = 0;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++) currSum += grid[i][j];
            preCol[j] = currSum;
        }
        return binary_search(preRow.begin(), preRow.end(), sum/2) || binary_search(preCol.begin(), preCol.end(), sum/2);
    }
};