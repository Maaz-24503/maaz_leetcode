class Solution {
private:
    vector<vector<pair<int, int>>> adjList;
    vector<long long> dist;  
    vector<unordered_map<int, int>> memo;  
    int n;

    void dk() {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minpq;
        minpq.push({0, 0});
        while (!minpq.empty()) {
            auto [score, node] = minpq.top();
            minpq.pop();
            if (score > dist[node]) continue;
            for (auto& [nei, jump] : adjList[node]) {
                if ((long long)jump + score < dist[nei]) {
                    minpq.push({(long long)jump + score, nei});
                    dist[nei] = (long long)jump + score;
                }
            }
        }
    }

    int dfs(int u, long long remaining) {
        if (remaining < 0) return 0;
        if (memo[u].count(remaining)) return memo[u][remaining];
        if (u == n - 1) return remaining == 0 ? 1 : 0;
        int ans = 0;
        for (auto& [v, score] : adjList[u]) {
            if (dist[v] == dist[n - 1] - (remaining - score)) 
                ans = (ans + dfs(v, remaining - score)) % 1000000007;
        }
        return memo[u][remaining] = ans;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        adjList.resize(n);
        this->n = n;
        for (const auto& road : roads) {
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }
        dist.resize(n, LLONG_MAX);  
        dist[0] = 0;
        dk();
        memo.resize(n);  
        return dfs(0, dist[n - 1]);
    }
};