class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> cost(n, INT_MAX);
        vector<int> dist(n, INT_MAX);
        cost[0] = passingFees[0];
        dist[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> dk;
        dk.push({cost[0], 0, dist[0]});
        while(!dk.empty()){
            vector<int> curr = dk.top();
            dk.pop();
            int c = curr[0], u = curr[1], d = curr[2];
            for(auto &[v, vDist] : adjList[u]){
                int vCost = passingFees[v];
                if(d + vDist > maxTime) continue;
                if(cost[v] == INT_MAX){
                    cost[v] = c + vCost;
                    dist[v] = d + vDist;
                    dk.push({vCost + c, v, dist[v]});
                } else if(d + vDist < dist[v]){
                    dist[v] = d + vDist;
                    dk.push({vCost + c, v, dist[v]});
                }
            }
        }
        return cost[n - 1] == INT_MAX ? -1 : cost[n - 1];
    }
};