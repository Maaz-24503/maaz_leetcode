class Solution {
private:
    int n, time;
    vector<vector<int>> adjList, ans;
    vector<bool> isVisited;
    vector<int> dis, sur;

    void dfs(int u = 0, int par = -1){
        if(isVisited[u]) return;
        isVisited[u] = true;
        dis[u] = sur[u] = time;
        time++;
        for(auto& v : adjList[u]){
            dfs(v, u);
        }
        for(auto& v : adjList[u]){
            if(v != par) sur[u] = min(sur[u], sur[v]);
        }
        for(auto& v : adjList[u]){
            if(v != par && dis[u] < sur[v]) ans.push_back({u, v}); 
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        this->n = n;
        adjList.resize(n);
        for(int i = 0; i<connections.size(); i++){
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        time = 0;
        isVisited.resize(n, false);
        dis.resize(n);
        sur.resize(n);
        dfs();
        return ans;
    }
};