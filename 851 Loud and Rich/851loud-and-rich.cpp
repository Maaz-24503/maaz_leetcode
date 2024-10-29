class Solution {
public:
    vector<pair<int, int>> memo;
    vector<vector<int>> adjList;
    pair<int, int> DFS(int u, vector<int>& quiet){
        if(memo[u].second != -1){
            // cout<<"in this case, "<<memo[u].second<<endl;
             return memo[u];
        }
        // cout<<u<<endl;
        if(adjList[u].size() == 0) return memo[u] = {quiet[u], u};
        pair<int, int> ans = {quiet[u], u};
        for(int i = 0; i<adjList[u].size(); i++){
            ans = min(ans, DFS(adjList[u][i], quiet));
        }
        return memo[u] = ans;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        adjList.resize(quiet.size());
        memo.resize(quiet.size(), {-1,-1});
        for(int i = 0; i<richer.size(); i++){
            adjList[richer[i][1]].push_back(richer[i][0]);
        }
        for(int i = 0; i<quiet.size(); i++){
            DFS(i, quiet);
        }
        vector<int> ans(quiet.size());
        for(int i = 0; i < quiet.size(); i++) ans[i] = memo[i].second;
        return ans;
    }
};