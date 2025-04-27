class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(int i = 0; i<connections.size(); i++){
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        int time = 0;
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<int> surr(n);
        vector<bool> isVisited(n, false);
        function<void(int,int)> dfs = [&](int u, int par){
            if(isVisited[u]) return;
            isVisited[u] = true;
            time++;
            t[u] = surr[u] = time;
            for(int& v : adjList[u]){
                if(v != par) dfs(v, u);
            }
            for(int& v : adjList[u]){
                if(v != par) surr[u] = min(surr[u], surr[v]);
            }
            for(int& v : adjList[u]){
                if(v != par && surr[v] > t[u]) ans.push_back({u, v});
            }
        };
        dfs(0, -1);
        return ans;
    }
};