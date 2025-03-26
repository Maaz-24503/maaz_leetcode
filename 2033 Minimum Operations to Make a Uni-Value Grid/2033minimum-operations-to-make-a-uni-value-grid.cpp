class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> flat;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                flat.push_back(grid[i][j]);
            }
        }
        sort(flat.begin(), flat.end());
        n = n*m;
        int med = flat[n/2], ans = 0;
        for(int i = 0; i<n; i++){
            if(abs(flat[i] - med) % x != 0) return -1;
            ans += abs(flat[i] - med)/x;
        }
        return ans;
    }
};