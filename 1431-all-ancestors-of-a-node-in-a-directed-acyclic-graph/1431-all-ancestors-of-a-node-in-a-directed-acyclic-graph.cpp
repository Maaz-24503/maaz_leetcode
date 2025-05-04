class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0)
                q.push(i);

        vector<unordered_set<int>> ancestors(n); 

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
                ancestors[v].insert(u);
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
