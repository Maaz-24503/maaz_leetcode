class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> memo(numRows, vector<int>(0));
        memo[0].push_back(1);
        for(int i = 1; i<numRows; i++){
            memo[i].push_back(1);
            for(int j = 0; j<i-1; j++) memo[i].push_back(memo[i-1][j] + memo[i-1][j+1]);
            memo[i].push_back(1);
        }
        return memo;
    }
};