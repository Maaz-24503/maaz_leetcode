class Solution {
private:
    vector<vector<int>> adjList;
    int n;
    vector<bool> isVisited;

    void DFS(int u, unordered_set<int>& elems){
        if(isVisited[u]) return;
        isVisited[u] = true;
        elems.insert(u);
        for(auto& v: adjList[u]){
            DFS(v, elems);
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        isVisited.resize(n, false);
        for(int i = 0; i<n; i++) {
            if(!isVisited[i]){
                unordered_set<int> elems;
                DFS(i, elems);
                int k = elems.size();
                bool isValid = true;
                for(auto& u : elems){
                    if(adjList[u].size() < k-1){
                        isValid = false;
                        break;
                    }
                }
                if(isValid) ans++;
            }
        }
        return ans;
    }
};