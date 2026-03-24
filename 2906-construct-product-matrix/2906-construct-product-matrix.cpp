class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> rightProd(n, vector<long long> (m, 1));
        int MOD = 12345;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) continue;
                int p = j == m - 1 ? i + 1 : i, q = (j + 1) % m;
                rightProd[i][j] = (rightProd[p][q] * grid[p][q]) % MOD;
            }
        }
        vector<vector<int>> ans(n, vector<int> (m));
        long long prod = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (prod * rightProd[i][j]) % MOD;
                prod = (prod * grid[i][j]) % MOD;
            }
        }
        return ans;
    }
};