class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
        // First calculate best option in tree 2 with k-1, jst need to add that val to everyth in tree1
        function<int(int,int,int)> dfs1 = [&](int u, int par, int moves){
            if(moves < 0) return 0;
            if(moves == 0) return 1;
            int ans = 1;
            for(int v : adjList2[u]) 
                if(v != par)
                    ans += dfs1(v, u, moves - 1);
            return ans;
        };
        int maxi = 0;
        for(int i = 0; i<m; i++){
            maxi = max(maxi, dfs1(i, -1, k-1));
            // cout<<dfs1(i, -1, k-1)<<endl;
        }

        function<int(int,int,int)> dfs2 = [&](int u, int par, int moves){
            if(moves < 0) return 0;
            if(moves == 0) return 1;
            int ans = 1;
            for(int v : adjList1[u]) 
                if(v != par)
                    ans += dfs2(v, u, moves - 1);
            return ans;
        };
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            ans[i] = dfs2(i, -1, k) + maxi;
        }
        return ans;
    }
};