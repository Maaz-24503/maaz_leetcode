class Solution {
public:
    vector<vector<int>> d{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    vector<vector<bool>> isVisited;
    vector<vector<char>> grid;

    bool isValid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    void DFS(int i, int j){
        if(!isValid(j, i)) return;
        if(isVisited[i][j] || grid[i][j] == '0') return;
        isVisited[i][j] = true;
        for(int k = 0; k<4; k++){
            DFS(i + d[k][0], j + d[k][1]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        isVisited.resize(n, vector<bool>(m, false));
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !isVisited[i][j]){
                    DFS(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};