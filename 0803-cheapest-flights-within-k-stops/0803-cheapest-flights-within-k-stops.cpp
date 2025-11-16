class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i<m; i++)
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        queue<vector<int>> q;
        q.push(vector<int>{src, 0, 0});
        vector<int> minVis(n, INT_MAX);
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            if(curr[1] > k) continue;
            for(int i = 0; i<adjList[curr[0]].size(); i++) 
                if(curr[2] + adjList[curr[0]][i].second < minVis[adjList[curr[0]][i].first]){
                    q.push(vector<int> {adjList[curr[0]][i].first, curr[1] + 1, curr[2] + adjList[curr[0]][i].second});
                    minVis[adjList[curr[0]][i].first] = curr[2] + adjList[curr[0]][i].second;
                }
        }
        return minVis[dst] == INT_MAX ? -1 : minVis[dst];
    }
};