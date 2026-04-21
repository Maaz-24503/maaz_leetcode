struct DSU {
    int _n;
    vector<int> parent, rank;
    
    DSU(int n){
        rank = vector<int> (n, 0);
        _n = n;
        parent = vector<int> (n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool join(int i, int j){
        int u = find(i), v = find(j);
        if(u == v) return false;
        if(rank[u] < rank[v]) parent[u] = v;
        else if(rank[v] < rank[u]) parent[v] = u;
        else {
            rank[u]++;
            parent[v] = u;
        }
        return true;
    }

    vector<vector<int>> getComponents(){
        vector<vector<int>> components(_n, vector<int>(0));
        unordered_set<int> done;
        for(int i = 0; i < _n; i++)
            components[find(i)].push_back(i);
        vector<vector<int>> ans;
        for(int i = 0; i < _n; i++) 
            if(components[i].size())
                ans.push_back(components[i]);
        return ans;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();    
        DSU uf(n);
        for(auto &edge : allowedSwaps)
            uf.join(edge[0], edge[1]);
        int same = 0;
        vector<vector<int>> segments = uf.getComponents();
        for(int i = 0; i < segments.size(); i++){
            unordered_map<int, int> a, b;
            for(int j = 0; j < segments[i].size(); j++){
                int ind = segments[i][j];
                a[source[ind]]++; b[target[ind]]++;
            }
            for(auto [u, f] : a){
                if(b.find(u) != b.end()) same += min(f, b[u]);
            }
        }
        return n - same;
    }
};