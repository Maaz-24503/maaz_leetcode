class Solution {
public:

    int helper(vector<vector<int>> memo, vector<vector<int>>& triangle, int i, int j){
        if(memo[i][j]!=-1) return memo[i][j];
        if(i==triangle.size()-1) {
            memo[i][j] =  triangle[i][j];
            return memo[i][j];
        } 
        memo[i][j] =  triangle[i][j] + min(helper(memo, triangle, i+1, j), helper(memo, triangle,i+1, j+1));
        return memo[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size(), -1));
        for(int i = triangle.size()-1; i>=0; i--){
            for(int j = 0; j<triangle[i].size(); j++){
                if(i==triangle.size()-1) memo[i][j] = triangle[i][j];
                else memo[i][j] = triangle[i][j] + min(memo[i+1][j], memo[i+1][j+1]);
            }
        }
        return helper(memo, triangle, 0, 0);
    }
};