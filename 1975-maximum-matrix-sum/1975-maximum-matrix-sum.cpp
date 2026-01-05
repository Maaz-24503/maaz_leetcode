class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size(), countNeg = 0, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += max(matrix[i][j], -matrix[i][j]);
                if(matrix[i][j] < 0) countNeg++;
                mini = min(max(matrix[i][j], -matrix[i][j]), mini);
            }
        }
        return countNeg % 2 == 0 ? sum : sum - 2*mini;
    }
};