class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> bfs;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    bfs.push({1, i, j});
        
        vector<vector<int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        function<bool(int, int)> isValid = [n](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < n;
        };
        
        while(!bfs.empty()){
            vector<int> curr = bfs.front(); bfs.pop();
            int d = curr[0], i = curr[1], j = curr[2];
            for(int k = 0; k < 4; k++){
                int ni = dir[k][0] + i, nj = dir[k][1] + j;
                if(!isValid(ni, nj) || grid[ni][nj]) continue;
                bfs.push({d + 1, ni, nj});
                grid[ni][nj] = d + 1;
            }
        }

        vector<vector<bool>> isVisited(n, vector<bool> (n, false));
        
        auto dfs = [&](int startI, int startJ, int target) -> bool {
            if(grid[startI][startJ] < target) return false;

            stack<pair<int,int>> st;
            st.push({startI, startJ});
            isVisited[startI][startJ] = true;

            while(!st.empty()){
                auto [i, j] = st.top(); st.pop();

                if(i == n - 1 && j == n - 1) return true;

                for(int k = 0; k < 4; k++){
                    int ni = dir[k][0] + i, nj = dir[k][1] + j;
                    if(isValid(ni, nj) && !isVisited[ni][nj] && grid[ni][nj] >= target){
                        isVisited[ni][nj] = true;
                        st.push({ni, nj});
                    }
                }
            }
            return false;
        };

        int l = 1, r = 2*n, ans = 1;
        while(l <= r){
            int mid = (l + r) / 2;
            isVisited = vector<vector<bool>> (n, vector<bool> (n, false));
            bool isFine = dfs(0, 0, mid);
            if(isFine){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans - 1;
    }
};