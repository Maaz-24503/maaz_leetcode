class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int maxEdge = 0;
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            if(online[edges[i][1]]){
                adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            }
            maxEdge = max(maxEdge, edges[i][2]);
        }
        function<bool(int)> dk = [&](int target) -> bool {
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0LL;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            pq.push({0, 0});
            while(!pq.empty()){
                auto [d, u] = pq.top(); pq.pop();
                if(d > dist[u]) continue;
                if(u == n - 1) return true;
                for(auto [v, cost] : adjList[u]){
                    long long nd = d + cost;
                    if(cost >= target && dist[v] > nd && k >= nd){
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
            return false;
        };
        int l = 0, r = maxEdge, ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(dk(mid)){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};