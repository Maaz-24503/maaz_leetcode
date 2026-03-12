struct DSU {
public:
    vector<int> parent, rankv;
    int components;

    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;

        components--;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU initial(n);
        vector<vector<int>> options;
        int lowestMust = INT_MAX;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][3] == 1){
                lowestMust = min(lowestMust, edges[i][2]);
                if(!initial.unite(edges[i][0], edges[i][1])) return -1;
            }
            else options.push_back(edges[i]);
        }

        function<bool(int, DSU)> check = [&](int guess, DSU dsu) -> bool {
            if(guess > lowestMust) return false;
            for(auto &edge : options)
                if(edge[2] >= guess) 
                    dsu.unite(edge[0], edge[1]);
            
            int upgrades = 0;

            for(auto &edge : options){
                if(edge[2] * 2 >= guess) {
                    if(dsu.unite(edge[0], edge[1])){
                        upgrades++;
                        if(upgrades > k) return false;
                    }
                }
            }
            return dsu.components == 1;
        };

        int l = 1, r = 2*(1e5) + 1, ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(mid, initial)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};