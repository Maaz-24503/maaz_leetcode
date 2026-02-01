class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adjList(n);
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, int>> bfs;
        bfs.push({0, 0});
        while(!bfs.empty()){
            auto [u, dist] = bfs.front(); bfs.pop();
            for(int &v : adjList[u]){
                if(d[v] != INT_MAX) continue;
                d[v] = dist + 1;
                bfs.push({v, dist + 1});
            }
        }
        int maxi = 0;
        for(int i = 1; i < n; i++){
            int p = patience[i], t = d[i] * 2;
            // Find the last message fired from source
            int last = (t - 1) - ((t - 1) % p);
            maxi = max(last + t, maxi);
        }
        return maxi + 1;
    }
};