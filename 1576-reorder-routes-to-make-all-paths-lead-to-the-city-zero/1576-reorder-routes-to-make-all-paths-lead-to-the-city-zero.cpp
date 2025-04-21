class Solution {
private:
    vector<vector<int>> undList;
    vector<unordered_set<int>> adjList;
    vector<bool> isVisited;

    int dfs(int u){
        isVisited[u] = true;
        int ans = 0;
        for(int& v : undList[u]){
            if(!isVisited[v]){
                ans += dfs(v);
                if(adjList[v].find(u) == adjList[v].end()) ans++;
            }
        }
        return ans;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        adjList.resize(n);
        undList.resize(n);
        for(int i = 0; i<n-1; i++) {
            int u = connections[i][0], v = connections[i][1];
            adjList[u].insert(v);
            undList[u].push_back(v);
            undList[v].push_back(u);
        }
        isVisited.resize(n, false);
        return dfs(0);
    }
};