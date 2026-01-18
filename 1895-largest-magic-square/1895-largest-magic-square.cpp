class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> horSum(n, vector<int> (m + 1, 0));
        vector<vector<int>> verSum(n + 1, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m + 1; j++){
                horSum[i][j] = horSum[i][j - 1] + grid[i][j - 1];
            }
        }
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n + 1; i++){
                verSum[i][j] = verSum[i - 1][j] + grid[i - 1][j];
            }
        }
        function<bool(int, int, int)> check = [&](int i, int j, int k) -> bool {
            // horizontal sum
            int sum = 0;
            for(int p = i; p < i + k; p++){
                if(p == i){
                    sum = horSum[i][j + k] - horSum[i][j];
                }
                else{
                    int currSum = horSum[p][j + k] - horSum[p][j];
                    if(currSum != sum) return false;
                }
            }
            // vertical sum
            for(int q = j; q < j + k; q++){
                int currSum = verSum[i + k][q] - verSum[i][q];
                if(currSum != sum) return false;
            }
            // main diagonal
            int currSum = 0;
            for(int p = 0; p < k; p++) currSum += grid[i + p][j + p];
            if(currSum != sum) return false;
            // anti diagonal
            currSum = 0;
            for(int p = 0; p < k; p++){
                int ii = i + p, jj = j + k - 1 - p;
                currSum += grid[ii][jj];
            }
            return currSum == sum;
        };
        for(int k = min(n, m); k >= 2; k--){
            for(int i = 0; i <= n - k; i++){
                for(int j = 0; j <= m - k; j++){
                    if(check(i, j, k)) return k;
                }
            }
        }
        return 1;   
    }
};