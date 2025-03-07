class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> memo(n+1, vector<int> (m+1, INT_MAX));
        memo[n-1][m] = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                memo[i][j] = min(memo[i+1][j], memo[i][j+1]) - dungeon[i][j];
                memo[i][j] = max(memo[i][j], 1);
            }
        }
        return memo[0][0];
    }
};