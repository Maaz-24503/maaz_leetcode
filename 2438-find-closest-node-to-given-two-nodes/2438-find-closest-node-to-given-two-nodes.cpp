class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        function<void(int,vector<int>&)> dijkstra = [&](int u, vector<int>& dist){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dk;
            dk.push({0, u});
            while(!dk.empty()){
                auto [d, nd] = dk.top();
                dk.pop();
                if(dist[nd] < d) continue;
                dist[nd] = d;
                if(edges[nd] == -1) continue;
                if(dist[edges[nd]] > d + 1)
                    dk.push({d + 1, edges[nd]});
            }
        };
        dijkstra(node1, dist1);
        dijkstra(node2, dist2);
        int mini = INT_MAX, ans = -1;
        for(int i = 0; i<n; i++) {
            if(max(dist1[i], dist2[i]) < mini){
                mini = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};