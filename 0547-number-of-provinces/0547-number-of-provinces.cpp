class UF{
private:
    vector<int> par, rank;
    int comp;
public:
    UF(int n){
        par.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i<n; i++) par[i] = i;
        comp = n;
    }

    int find(int u){
        if(u == par[u]) return u;
        int pathComp = find(par[u]);
        par[u] = pathComp;
        return pathComp;
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        comp--;
        if(rank[u] > rank[v]) par[v] = u;
        else if(rank[u] < rank[v]) par[u] = par[v];
        else{
            par[u] = v;
            rank[v]++;
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
        UF dsu = UF(n);
        for(int i = 0; i<n-1; i++)
            for(int j = i+1; j<n; j++)
                if(isConnected[i][j]) 
                    dsu.merge(i, j);
        return dsu.components();
    }
};