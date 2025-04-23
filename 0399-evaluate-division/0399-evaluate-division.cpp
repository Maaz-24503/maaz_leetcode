class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> ind;
        vector<string> name;

        for(int i = 0; i<equations.size(); i++){
            if(!ind.count(equations[i][0])){
                ind[equations[i][0]] = name.size();
                name.push_back(equations[i][0]);
            }
            if(!ind.count(equations[i][1])){
                ind[equations[i][1]] = name.size();
                name.push_back(equations[i][1]);
            }
        }

        int n = name.size();
        vector<vector<pair<int, double>>> adjList(n);

        for(int i = 0; i<equations.size(); i++){
            int u = ind[equations[i][0]], v = ind[equations[i][1]];
            adjList[u].push_back({v, values[i]});
            adjList[v].push_back({u, 1/values[i]});
        }

        vector<unordered_map<int, double>> memo(n);

        function<double(int,int,vector<bool>&)> dfs = [&](int u, int v, vector<bool>& isVisited) -> double {
            if(u == v) return 1.0;
            if(memo[u].count(v)) return memo[u][v];
            if(isVisited[u]) return -1.0;
            isVisited[u] = true;
            set<double> ans;
            for(auto [vert, val] : adjList[u]){
                double num = dfs(vert, v, isVisited);
                if(num > 0.0) ans.insert(num * val);
            }
            isVisited[u] = false;
            if(ans.size() == 1) return memo[u][v] = *ans.begin();
            else return -1.0;
        };

        vector<double> ans;
        for(int i = 0; i<queries.size(); i++){
            if(ind.count(queries[i][0]) && ind.count(queries[i][1])) {
                vector<bool> isVisited(n, false);
                ans.push_back(dfs(ind[queries[i][0]], ind[queries[i][1]], isVisited));
            }
            else ans.push_back(-1.0);
        }
        return ans;
    }
};