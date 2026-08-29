struct DSU {
    int n;
    vector<int> rank, parent;

    DSU(int n_){
        n = n_;
        rank = vector<int> (n_, 0);
        parent = vector<int> (n_, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u){
        if(u == parent[u]) return u;
        int par = parent[u];
        return parent[u] = par;
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] == rank[v]){
            rank[u]++;
            parent[v] = u;
        } else {
            if(rank[u] > rank[v]) parent[v] = u;
            else parent[u] = v;
        }
    }

    vector<vector<int>> getComponents(){
        unordered_map<int, int> ind;
        vector<vector<int>> components;
        for(int i = 0; i < n; i++){
            int par = find(i);
            if(ind.find(par) == ind.end()) {
                ind[par] = components.size();
                components.push_back({i});
            }
            else {
                components[ind[par]].push_back(i);
            }
        }
        return components;
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> sorted(n);
        for(int i = 0; i < n; i++) sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end());
        DSU uf(n);
        for(int i = 0; i < n - 1; i++){
            if(sorted[i + 1][0] - sorted[i][0] <= limit){
                uf.merge(sorted[i][1], sorted[i + 1][1]);
            }
        }
        vector<vector<int>> components = uf.getComponents();
        vector<int> ans(n);
        for(int i = 0; i < components.size(); i++){
            vector<int> indices, elements;
            for(int j = 0; j < components[i].size(); j++){
                elements.push_back(nums[components[i][j]]);
                indices.push_back(components[i][j]);
            }
            sort(elements.begin(), elements.end());
            sort(indices.begin(), indices.end());
            for(int k = 0; k < indices.size(); k++) ans[indices[k]] = elements[k];
        }
        return ans;
    }
};