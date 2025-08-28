class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> diags;
        int diagonals = 2 * n - 1;
        for(int i = 0; i<diagonals; i++){
            diags.push_back(vector<int>{});
            if(i < n - 1){
                int y = 0, x = n - i - 1;
                while(x < n) diags[i].push_back(grid[y++][x++]);
                sort(diags[i].begin(), diags[i].end());
            } else {
                int y = i - (n - 1), x = 0;
                while(y < n) diags[i].push_back(grid[y++][x++]);
                sort(diags[i].begin(), diags[i].end(), [](auto &a, auto &b){
                    return a > b;
                });
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i = 0; i<diagonals; i++){
            int count = 0;
            if(i < n - 1){
                int y = 0, x = n - i - 1;
                while(x < n) ans[y++][x++] = diags[i][count++];
            } else {
                int y = i - (n - 1), x = 0;
                while(y < n) ans[y++][x++] = diags[i][count++];
            }
        }
        return ans;
    }
};