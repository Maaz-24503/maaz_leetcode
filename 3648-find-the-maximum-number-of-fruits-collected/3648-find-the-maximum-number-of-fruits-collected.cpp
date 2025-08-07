class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        
        vector<vector<int>> memo2(n, vector<int>(n, -1));
        vector<vector<int>> memo3(n, vector<int>(n, -1));
        
        function<int(int, int)> helper2 = [&](int i, int j) -> int {
            if (i == n-1 && j == n-1) return fruits[i][j];
            if (i < 0 || i >= n || j < 0 || j >= n || i >= j) return -1e9;
            if (memo2[i][j] != -1) return memo2[i][j];
            
            
            int maxFruits = -1e9;
            vector<pair<int,int>> directions{{1,-1}, {1,0}, {1,1}};
            
            for (auto [dr, dc] : directions) {
                int ni = i + dr;
                int nj = j + dc;
                int result = helper2(ni, nj);
                if (result != -1e9) {
                    maxFruits = max(maxFruits, result);
                }
            }
            
            if (maxFruits != -1e9) maxFruits += fruits[i][j];
            return memo2[i][j] = maxFruits;
        };
        
        function<int(int, int)> helper3 = [&](int i, int j) -> int {
            if (i == n-1 && j == n-1) return fruits[i][j];
            if (i < 0 || i >= n || j < 0 || j >= n || i <= j) return -1e9;
            if (memo3[i][j] != -1) return memo3[i][j];

            int maxFruits = -1e9;
            vector<pair<int,int>> directions{{-1,1}, {0,1}, {1,1}};
            for (auto [dr, dc] : directions) {
                int ni = i + dr;
                int nj = j + dc;
                int result = helper3(ni, nj);
                if (result != -1e9) {
                    maxFruits = max(maxFruits, result);
                }
            }
            if (maxFruits != -1e9) maxFruits += fruits[i][j];
            return memo3[i][j] = maxFruits;
        };
        
        int best2 = helper2(0, n-1);
        if (best2 == -1e9) best2 = 0;
        
        int best3 = helper3(n-1, 0);
        if (best3 == -1e9) best3 = 0;
        
        return ans + best2 + best3;
    }
};