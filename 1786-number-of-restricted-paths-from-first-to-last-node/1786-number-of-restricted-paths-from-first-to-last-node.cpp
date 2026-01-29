class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0] - 1].push_back({edges[i][1] - 1, edges[i][2]});
            adjList[edges[i][1] - 1].push_back({edges[i][0] - 1, edges[i][2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<>> dk;
        vector<int> dist(n, INT_MAX);
        dk.push({0, n - 1}); dist[n - 1] = 0;
        while(!dk.empty()){
            vector<int> curr = dk.top(); dk.pop();
            int c = curr[0], u = curr[1];
            if(c > dist[u]) continue;
            for(auto [v, w] : adjList[u]){
                if(w + c < dist[v]){
                    dist[v] = c + w;
                    dk.push({dist[v], v});
                }
            }
        }
        int MOD = 1e9 + 7;
        vector<int> dp(n, -1);
        function<int(int)> helper = [&](int u) -> int {
            if(dp[u] != -1) return dp[u];
            if(u == n - 1) return dp[u] = 1;
            int ans = 0;
            for(auto [v, _] : adjList[u]){
                if(dist[v] < dist[u]){
                    ans = (ans + helper(v)) % MOD;
                }
            }
            return dp[u] = ans;
        };
        return helper(0);
    }
};