class Solution {
public:
    vector<vector<int>> adjList;
    int n;
    int bfs(){
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> isVisited(n, false);
        isVisited[0] = true;
        while(!q.empty()){
            auto [ind, moves] = q.front();
            q.pop();
            for(int i = 0; i<adjList[ind].size(); i++){
                if(adjList[ind][i] == n-1) return moves+1;
                if(!isVisited[adjList[ind][i]]){
                    isVisited[adjList[ind][i]] = true;
                    q.push({adjList[ind][i], moves+1});
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        this->n = n;
        this->adjList.resize(n);
        for(int i = 1; i<n; i++) adjList[i-1].push_back(i);
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            adjList[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(bfs());
        }
        return ans;
    }
};