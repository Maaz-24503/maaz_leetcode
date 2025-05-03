class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> dp(n, -1);
        function<bool(int)> dfs = [&](int u){
            if(dp[u] != -1) return dp[u];
            state[u] = 1;
            for(int v : graph[u]){
                if(state[v] == 1) return dp[u] = false;
                else if(!dfs(v)) return dp[u] = false; 
            }
            state[u] = 2;
            return dp[u] = true;
        };
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(dfs(i)) ans.push_back(i);
        }
        return ans;
    }
};