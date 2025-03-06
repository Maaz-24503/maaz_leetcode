class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans{-1, -1};
        vector<bool> isSeen(n*n, false);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isSeen[grid[i][j] - 1]) ans[0] = grid[i][j];
                else isSeen[grid[i][j] - 1] = true;
            }
        }
        for(int i = 0; i<n*n; i++) 
            if(!isSeen[i]){
                ans[1] = i+1;
                break;
            }
        return ans;
    }
};