class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(int i = 0; i<mines.size(); i++) grid[mines[i][0]][mines[i][1]] = 0;
        int largest = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    for(int k = 0; k<n; k++){
                        if(i<k || j<k || i+k>=n || j+k>=n) break;
                        if(grid[i+k][j] == 0 || grid[i][j+k] == 0 || grid[i-k][j] == 0 || grid[i][j-k] == 0) break;
                        largest = max(largest, k+1);
                    }
                }
            }
        }
        return largest;
    }
};