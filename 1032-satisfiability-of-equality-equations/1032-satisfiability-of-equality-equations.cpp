class UnionFind{
private:
    vector<int> rank, parent;
public:
    UnionFind(int n){
        rank.resize(n, 0);
        for(int i = 0; i<n; i++) parent.push_back(i);
    }

    int find(int u){
        if(parent[u] == u) return u;
        int ans = find(parent[u]);
        parent[u] = ans;    // path comp
        return ans;
    }

    void merge(int u, int v){
        u = find(u); v = find(v);
        if(rank[u] == rank[v]){
            rank[u]++;
            parent[v] = u;
        }
        else if(rank[u] < rank[v]) parent[u] = v;
        else parent[v] = u;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, int> elems;
        int n = equations.size();
        int ind = 0;
        for(int i = 0; i<n; i++){
            if(elems.find(equations[i][0]) == elems.end()) elems[equations[i][0]] = ind++;
            if(elems.find(equations[i][3]) == elems.end()) elems[equations[i][3]] = ind++;
        }
        vector<pair<int, int>> notEq;
        UnionFind dsu(elems.size());
        for(int i = 0; i<n; i++){
            if(equations[i][1] == '!') notEq.push_back({elems[equations[i][0]], elems[equations[i][3]]});
            else dsu.merge(elems[equations[i][0]], elems[equations[i][3]]);
        }
        for(int i = 0; i<notEq.size(); i++) if(dsu.find(notEq[i].first) == dsu.find(notEq[i].second)) return false;
        return true;
    }
};