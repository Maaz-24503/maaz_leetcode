class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);
        vector<vector<int>> revList(n);
        for(int i = 0; i < invocations.size(); i++){
            adjList[invocations[i][0]].push_back(invocations[i][1]);
            revList[invocations[i][1]].push_back(invocations[i][0]);
        }
        unordered_set<int> rem;
        function<void(int)> dfs = [&](int u) -> void {
            if(rem.find(u) != rem.end()) return;
            rem.insert(u);
            for(const int &v : adjList[u]){
                dfs(v);
            }
        };
        dfs(k);
        vector<int> noRemovalAns(n);
        iota(noRemovalAns.begin(), noRemovalAns.end(), 0); 
        for(const int &u : rem){
            for(const int &v : revList[u]) {
                if(!rem.count(v)) return noRemovalAns; 
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(rem.find(i) == rem.end()) ans.push_back(i);
        }
        return ans;
    }
};