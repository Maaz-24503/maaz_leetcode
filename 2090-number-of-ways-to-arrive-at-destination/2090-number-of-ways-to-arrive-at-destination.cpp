class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i<roads.size(); i++){
            adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        dist[n-1] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> dk;
        dk.push({0, n-1});
        while(!dk.empty()){
            auto [cost, node] = dk.top();
            dk.pop();
            if(cost > dist[node]) continue;
            for(auto [nei, edgeWeight] : adjList[node]){
                if(edgeWeight + cost < dist[nei]){
                    dist[nei] = edgeWeight + cost;
                    dk.push({edgeWeight + cost, nei});
                }
            }
        }
        vector<int> dp(n, -1);
        dp[n-1] = 1;
        function<int(int)> dfs = [&](int u){
            if(dp[u] != -1) return dp[u];
            dp[u] = 0;
            for(auto [nei, edgeWeight] : adjList[u]){
                if(edgeWeight + dist[nei] == dist[u]){
                    dp[u] += dfs(nei);
                    dp[u] %= 1000000007;
                }
            }
            return dp[u];
        };
        return dfs(0);
    }
};