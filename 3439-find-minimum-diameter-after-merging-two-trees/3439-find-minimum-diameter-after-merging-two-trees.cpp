class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adjList1(n);
        vector<vector<int>> adjList2(m);
        for(int i = 0; i<n - 1; i++){
            adjList1[edges1[i][0]].push_back(edges1[i][1]);
            adjList1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i<m - 1; i++){
            adjList2[edges2[i][0]].push_back(edges2[i][1]);
            adjList2[edges2[i][1]].push_back(edges2[i][0]);
        }
        function<pair<int, int>(int, int, vector<vector<int>>&)> furthest = [&](int u, int par, vector<vector<int>>& graph){
            pair<int, int> maxi = {0, u};
            for(int v : graph[u]){
                if(v != par) {
                    auto [dist, nd] = furthest(v, u, graph);
                    maxi = max(maxi, {1 + dist, nd}); 
                }
            }
            return maxi;
        };
        function<int(int, int, vector<vector<int>>&)> diameter = [&](int u, int par, vector<vector<int>>& graph){
            int maxi = 0;
            for(int v : graph[u])
                if(v != par) 
                    maxi = max(maxi, 1 + diameter(v, u, graph));
            return maxi;
        };
        pair<int, int> furthest1 = furthest(0, -1, adjList1), furthest2 = furthest(0, -1, adjList2);
        int d1 = diameter(furthest1.second, -1, adjList1), d2 = diameter(furthest2.second, -1, adjList2);
        return max((d1 + 1) / 2 + (d2 + 1) / 2 + 1, max(d1, d2));
    }
};