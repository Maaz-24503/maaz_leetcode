class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> preSum = matrix;
        for(int j = 0; j < m; j++) {
            for(int i = 1; i < n; i++) {
                preSum[i][j] = matrix[i][j] ? matrix[i][j] + preSum[i - 1][j] : 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            sort(preSum[i].rbegin(), preSum[i].rend());
            for(int j = 0; j < m; j++)
                ans = max(ans, preSum[i][j] * (j + 1));
        }
        return ans;
    }
};