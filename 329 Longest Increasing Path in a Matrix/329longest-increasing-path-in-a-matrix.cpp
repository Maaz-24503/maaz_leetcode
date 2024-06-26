class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& matrix){
        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = 0;
        if(i>0 && matrix[i-1][j]>matrix[i][j]) memo[i][j] = max(memo[i][j], 1 + helper(i-1, j, memo, matrix));
        if(i<matrix.size()-1 && matrix[i+1][j]>matrix[i][j]) memo[i][j] = max(memo[i][j], 1 + helper(i+1, j, memo, matrix));
        if(j>0 && matrix[i][j-1]>matrix[i][j]) memo[i][j] = max(memo[i][j], 1 + helper(i, j-1, memo, matrix));
        if(j<matrix[0].size()-1 && matrix[i][j+1]>matrix[i][j]) memo[i][j] = max(memo[i][j], 1 + helper(i, j+1, memo, matrix));
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(),vector<int>(matrix[0].size()+1, -1));
        int maxi = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                maxi = max(maxi, helper(i,j,memo,matrix));
            }
        }
        return maxi + 1;
    }
};