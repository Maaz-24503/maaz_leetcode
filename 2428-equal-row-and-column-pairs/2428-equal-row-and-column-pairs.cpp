class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        int n = grid.size();
        for(int i = 0; i<n; i++) rows[grid[i]]++;
        int ans = 0;
        for(int i = 0; i<n; i++){
            vector<int> col;
            for(int j = 0; j<n; j++) col.push_back(grid[j][i]);
            if(rows.find(col) != rows.end()) ans += rows[col];
        }
        return ans;
    }
};