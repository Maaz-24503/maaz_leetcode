class Solution{
public:
    int minCost(int n, vector<vector<int>> &edges){
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> dk;
        dk.push({0, 0});
        dist[0] = 0;
        while(!dk.empty()){
            vector<int> curr = dk.top();
            dk.pop();
            int cost = curr[0], u = curr[1];
            if(u == n - 1) return cost;
            for(auto [v, c] : adjList[u]){
                if(c + cost < dist[v]){
                    dist[v] = c + cost;
                    dk.push({c + cost, v});
                }
            }
        } 
        return -1;
    }
};