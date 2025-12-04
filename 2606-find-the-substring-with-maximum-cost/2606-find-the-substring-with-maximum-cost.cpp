class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26);
        for(int i = 0; i<26; i++) cost[i] = i + 1;
        for(int i = 0; i<chars.size(); i++) cost[chars[i] - 'a'] = vals[i];
        int n = s.size();
        vector<int> mapped(n, 0);
        for(int i = 0; i<n; i++) 
            mapped[i] = cost[s[i] - 'a'];
        int sum = 0, maxi = 0;
        for(int i = 0; i<n; i++){
            sum = max(sum + mapped[i], 0);
            maxi = max(maxi, sum);
        } 
        return maxi;
    }
};