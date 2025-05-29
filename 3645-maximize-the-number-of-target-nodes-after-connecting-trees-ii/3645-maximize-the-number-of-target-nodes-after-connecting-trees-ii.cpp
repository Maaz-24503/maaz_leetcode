class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adjList1(n);
        vector<vector<int>> adjList2(m);
        for(int i = 0; i<n-1; i++){
            adjList1[edges1[i][0]].push_back(edges1[i][1]);
            adjList1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i<m-1; i++){
            adjList2[edges2[i][0]].push_back(edges2[i][1]);
            adjList2[edges2[i][1]].push_back(edges2[i][0]);
        }
        function<int(int,int,bool)> dfs1 = [&](int u, int par, bool turn){
            int ans = turn ? 1 : 0;
            for(int v : adjList2[u]) if(v != par) ans += dfs1(v, u, !turn);
            return ans;
        };
        int maxi = dfs1(0, -1, true);
        maxi = max(maxi, m - maxi);
        vector<bool> color(n);
        function<int(int,int,bool)> dfs2 = [&](int u, int par, bool turn){
            int ans = turn ? 1 : 0;
            color[u] = turn;
            for(int v : adjList1[u]) if(v != par) ans += dfs2(v, u, !turn);
            return ans;
        };
        int trueColor = dfs2(0, -1, true);
        int falseColor = n - trueColor;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            ans[i] = (color[i] ? trueColor : falseColor) + maxi;
        }
        return ans;
    }
};