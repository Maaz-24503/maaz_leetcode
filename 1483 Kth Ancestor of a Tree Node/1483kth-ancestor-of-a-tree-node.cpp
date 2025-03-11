class TreeAncestor {
private:
    vector<vector<int>> spTable;
public:
    TreeAncestor(int n, vector<int>& parent) {
        int lg = 0;
        while ((1 << lg) <= n) lg++;
        
        spTable.resize(n, vector<int>(lg, -1));
        
        for (int i = 0; i < n; i++) 
            spTable[i][0] = parent[i];

        for (int j = 1; j < lg; j++) {
            for (int i = 0; i < n; i++) {
                if (spTable[i][j - 1] != -1) {
                    spTable[i][j] = spTable[spTable[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int i = 0;
        while (k > 0) {
            if (k & 1) { 
                node = spTable[node][i];
                if (node == -1) return -1;
            }
            k >>= 1;
            i++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */