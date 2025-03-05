class UnionFind {
private:
    vector<int> parent;
    vector<int> height;
public:
    UnionFind(int n){
        for(int i = 0; i<n; i++){
            parent.push_back(i);
            height.push_back(0);
        }
    }
    int find(int u){
        while(parent[u] != u) u = parent[u];
        return u;
    }
    void merge(int u1, int u2){
        if(find(u1) == find(u2)) return;
        while(u1 != parent[u1]) u1 = parent[u1];
        while(u2 != parent[u2]) u2 = parent[u2];
        if(height[u1] > height[u2]){
            parent[u2] = u1;
        }
        else{
            if(height[u1] == height[u2]) height[u2]++;
            parent[u1] = u2;
        }
    }
    int numComponents(){
        int count = 0;
        for(int i = 0; i<parent.size(); i++) if(parent[i] == i) count++;
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++) if(isConnected[i][j]) uf.merge(i, j);
        }
        return uf.numComponents();
    }
};