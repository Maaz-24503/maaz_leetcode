class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> id;
        unordered_set<int> lens;
        
        int n = original.size();
        int sz = 0;
        
        vector<vector<long long>> dist(201, vector<long long>(201, LLONG_MAX));
        
        for(int i = 0; i < n; i++){
            string& s = original[i];
            string& t = changed[i];
            
            if(id.find(s) == id.end()){
                id[s] = sz++;
                lens.insert(s.size());
            }
            if(id.find(t) == id.end()){
                id[t] = sz++;
            }
            
            int row = id[s];
            int col = id[t];
            dist[row][col] = min(dist[row][col], (long long)cost[i]);
        }
        
        for(int i = 0; i < sz; i++) dist[i][i] = 0;
        
        for(int k = 0; k < sz; k++){
            for(int i = 0; i < sz; i++){
                if(dist[i][k] < LLONG_MAX){
                    for(int j = 0; j < sz; j++){
                        if(dist[k][j] < LLONG_MAX){
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        
        int m = source.size();
        vector<long long> dp(m + 1, LLONG_MAX);
        dp[0] = 0;
        
        for(int i = 0; i < m; i++){
            if(dp[i] == LLONG_MAX) continue;
            
            if(source[i] == target[i]){
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            
            for(int len : lens){
                if(i + len > m) continue;
                
                string s_sub = source.substr(i, len);
                string t_sub = target.substr(i, len);
                
                if(id.find(s_sub) == id.end() || id.find(t_sub) == id.end()) continue;
                
                int x = id[s_sub];
                int y = id[t_sub];
                
                if(dist[x][y] < LLONG_MAX){
                    dp[i + len] = min(dp[i + len], dp[i] + dist[x][y]);
                }
            }
        }
        
        return dp[m] == LLONG_MAX ? -1 : dp[m];
    }
};