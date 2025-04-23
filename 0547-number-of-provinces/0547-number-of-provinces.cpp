class UnionFind{
private:
    vector<int> parent, rank;
    int comp;

public:
    UnionFind(int n){
        comp = n;
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        rank.resize(n, 1);
    }

    int find(int u){
        if(u == parent[u]) return u;
        int par = find(parent[u]);
        parent[u] = par;
        return par;
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        comp--;
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else{
            rank[u]++;
            parent[v] = u;
        }
    }

    int components(){
        return comp;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind dsu = UnionFind(n);
        for(int i = 0; i<n-1; i++)
            for(int j = i+1; j<n; j++)
                if(isConnected[i][j])
                    dsu.merge(i, j);
        return dsu.components();
    }
};