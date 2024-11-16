class Solution {
public:
    int n, m;
    vector<vector<int>> memo;
    vector<vector<int>> d{{-1,1}, {0,1}, {1,1}};

    bool isValid(int x, int y){
        return (x<n && y<m && x>=0 && y>=0);
    }

    int DFS(int i, int j, vector<vector<int>>& grid){
        if(j == m) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int maxi = INT_MIN;
        for(int k = 0; k<3; k++){
            if(isValid(i+d[k][0], j + d[k][1])){
                if(grid[i+d[k][0]][j + d[k][1]] > grid[i][j])
                    maxi = max(maxi, 1 + DFS(i + d[k][0], j + d[k][1], grid));
            }
        }
        return memo[i][j] = maxi==INT_MIN?0:maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo.resize(grid.size()+1, vector<int> (grid[0].size()+1, -1));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, DFS(i, 0, grid));
        }
        return maxi;
    }
};