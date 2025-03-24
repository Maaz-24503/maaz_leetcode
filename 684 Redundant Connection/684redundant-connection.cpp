class Solution {
private:
    int to, from, n;
    vector<vector<int>> adjList;
    vector<int> state;
    vector<vector<int>> options;
    bool isLoop;

    void dfs(int u = 0, int par = -1){
        if(state[u] == 1){
            to = u;
            from = par;
            isLoop = true;
            options.push_back({min(from + 1, to + 1), max(from + 1, to + 1)});
            return;
        }
        state[u] = 1;
        for(auto& v: adjList[u]){
            if(state[v] != 2 && v != par) dfs(v, u);
            if(isLoop){
                if(to == u) {
                    isLoop = false;
                    return;
                }
                options.push_back({min(par + 1, u + 1), max(par + 1, u + 1)});
                return;
            }
        }
        state[u] = 2;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        adjList.resize(n);
        state.resize(n, 0);
        unordered_map<string, int> ind;
        for(int i = 0; i<n; i++){
            edges[i] = {min(edges[i][0], edges[i][1]), max(edges[i][0], edges[i][1])};
            string key = to_string(edges[i][0]) + " " + to_string(edges[i][1]);
            ind[key] = i;
            adjList[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adjList[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        isLoop = false;
        dfs();
        int maxi = 0;
        for(int i = 0; i<options.size(); i++){
            string key = to_string(options[i][0]) + " " + to_string(options[i][1]);
            if(ind[key] > maxi) maxi = ind[key];
            // cout<<key<<": "<<ind[key]<<endl;
        }

        return edges[maxi];
    }
};