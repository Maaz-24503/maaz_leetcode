class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> preSum(n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++){
            int rowSum = 0;
            for(int j = 1; j <= m; j++){
                rowSum +=  mat[i - 1][j - 1];
                preSum[i][j] = rowSum + preSum[i - 1][j];
            }
        }
        function<int(int, int, int)> calcSum = [&](int i, int j, int k) -> int {
            return preSum[i + k][j + k] - 
                   preSum[i + k][j] + 
                   preSum[i][j] - 
                   preSum[i][j + k];
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int l = 0, r = min(n - i, m - j), currAns = 0;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(calcSum(i, j, mid) <= threshold){
                        currAns = mid;  
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                ans = max(ans, currAns);
            }
        }
        return ans;
    }
};