class Solution {
private:
    vector<vector<int>> adjList;
    vector<bool> isVisited;
    vector<int> dist;
    vector<int> path;

    void dfs(int u, int currDist){
        isVisited[u] = true;
        dist[u] = currDist;
        for(int& v : adjList[u]){
            if(!isVisited[v]) dfs(v, currDist + 1);
        }
    }

    bool dfs2(int u, int dest){
        if(u == dest){
            path.push_back(u);
            return true;
        }
        isVisited[u] = true;
        for(int& v : adjList[u]){
            if(!isVisited[v]) 
                if(dfs2(v, dest)){
                    path.push_back(u);
                    return true;
                }
        }
        return false;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(int i = 0; i<n-1; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        isVisited = vector<bool> (n, false);
        dist = vector<int> (n);
        dfs(0, 0);
        int src = 0, maxi = 0;
        for(int i = 0; i<n; i++){
            if(dist[i] > maxi){
                maxi = dist[i];
                src = i;
            }
        }
        isVisited = vector<bool> (n, false);
        dist = vector<int> (n);
        dfs(src, 0);
        int dest = 0;
        maxi = 0;
        for(int i = 0; i<n; i++){
            if(dist[i] > maxi){
                maxi = dist[i];
                dest = i;
            }
        }
        isVisited = vector<bool> (n, false);
        dfs2(src, dest);
        // for(int i = 0; i<path.size(); i++) cout<<path[i]<<" ";
        // cout<<endl;
        vector<int> ans;
        if(path.size() % 2){
            ans.push_back(path[path.size()/2]);
        }
        else{
            ans.push_back(path[path.size()/2]);
            ans.push_back(path[(path.size()/2) - 1]);
        }
        return ans;
    }
}; 