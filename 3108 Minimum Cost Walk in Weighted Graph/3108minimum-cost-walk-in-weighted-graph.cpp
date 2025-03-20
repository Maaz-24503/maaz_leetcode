class UF {
private:
    vector<int> rank, par;
    int n;

public:
    UF(int n) {
        this->n = n;
        rank.resize(n, 1);
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int k) {
        if(par[k] != k) {
            par[k] = find(par[k]);
        }
        return par[k];
    }

    void combine(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        
        if(rootI == rootJ) return; 
        
        if(rank[rootI] < rank[rootJ]) {
            par[rootI] = rootJ;
        }
        else if(rank[rootI] > rank[rootJ]) {
            par[rootJ] = rootI;
        }
        else {
            par[rootJ] = rootI;
            rank[rootI]++;  
        }
    }

    bool isCommon(int i, int j) {
        return find(i) == find(j);
    }
};


class Solution {
private:
    vector<vector<pair<int, int>>> adjList;
    vector<int> cost;
    vector<bool> isVisited;
    UF* unionFind;
    int score;
    int n;

    void DFS(int u){
        isVisited[u] = true;
        for(auto [v, w] : adjList[u]){
            score = score & w;
            if(!isVisited[v]) {
                DFS(v);
                unionFind->combine(u, v);
            }
        }
        // cout<<score<<endl;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        this->n = n;
        adjList.resize(n);
        for(int i = 0; i<edges.size(); i++){ 
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        isVisited.resize(n, false);
        unionFind = new UF(n);
        cost.resize(n);
        for(int i = 0; i<n; i++){
            score = INT_MAX;
            if(!isVisited[i]){
                DFS(i);
                cost[unionFind->find(i)] = score;
            }
        }
        vector<int> ans(query.size());
        for(int i = 0; i<query.size(); i++){
            if(unionFind->isCommon(query[i][0], query[i][1])) ans[i] = cost[unionFind->find(query[i][0])];
            else ans[i] = -1;
        }
        return ans;
    }
};