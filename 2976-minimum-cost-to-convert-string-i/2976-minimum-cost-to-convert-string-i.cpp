class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<pair<int, int>>> adjList(26);
        for(int i = 0; i < n; i++)
            adjList[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        vector<vector<int>> shortest(26, vector<int> (26, INT_MAX));
        for(int i = 0; i<26; i++) shortest[i][i] = 0;
        function<void(int)> dijkstras = [&](int c) -> void {
            vector<int> *dist = &(shortest[c]);
            priority_queue<vector<int>, vector<vector<int>>, greater<>> dk;
            dk.push({0, c});
            while(!dk.empty()){
                vector<int> curr = dk.top(); dk.pop();
                int d = curr[0], u = curr[1];
                if((*dist)[u] < d) continue;
                for(auto [v, weight] : adjList[u]){
                    if((*dist)[v] > d + weight){
                        (*dist)[v] = d + weight;
                        dk.push({d + weight, v});
                    }
                }
            }
        };
        for(int i = 0; i < 26; i++) dijkstras(i);
        long long ans = 0LL;
        for(int i = 0; i < source.size(); i++){
            int cost = shortest[source[i] - 'a'][target[i] - 'a'];
            if(cost == INT_MAX) return -1LL;
            ans = ans + shortest[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};