class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n);
        int m = dislikes.size();
        for(int i = 0; i<m; i++){
            adjList[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            adjList[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        vector<int> color(n, -1);
        function<bool(int)> dfs = [&](int u){
            for(int& v : adjList[u]){
                if(color[v] == -1){
                    color[v] = color[u] ? 0 : 1;
                    if(!dfs(v)) return false;
                }
                else if(color[v] == color[u]) return false;
            }
            return true;
        };
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
};