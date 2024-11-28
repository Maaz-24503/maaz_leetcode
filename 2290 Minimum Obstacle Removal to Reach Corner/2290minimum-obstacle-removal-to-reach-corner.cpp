class Solution {
public:
    vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
    int n, m;
    vector<vector<bool>> isVisited;

    bool isValid(int i, int j){
        return (i>=0) && (j>=0) && (i<n) && (j<m) && (!this->isVisited[i][j]);
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<vector<int>> q;
        n = grid.size();
        m = grid[0].size();
        isVisited.resize(n, vector<bool>(m, false));
        q.push({0,0,0});
        while(!q.empty()){
            vector<int> temp = q.top();
            int score = -temp[0];
            int y = temp[1];
            int x = temp[2];
            // cout<<y<<" "<<x<<endl;
            q.pop();
            for(int i = 0; i<4; i++){
                int currY = y + dy[i], currX = x + dx[i];
                if(isValid(currY, currX)){
                    isVisited[currY][currX] = true;
                    if(currY == n-1 && currX == m-1) return score;
                    if(grid[currY][currX] == 1) q.push({-score-1, currY, currX});
                    else q.push({-score, currY, currX});
                }
            }
        }
        return -1;
    }
};