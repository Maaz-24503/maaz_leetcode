class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long>  rows;
        for(int i = 0; i<points.size(); i++) rows[points[i][1]]++;
        for(auto [y, count]: rows) rows[y] = (count*(count-1))/2;
        long long sum = 0LL;
        int MOD = 1e9 + 7, ans = 0;
        for(auto [y, comb]: rows) {
            ans = (ans + (sum * comb) % MOD) % MOD;
            sum += comb;
        }
        return ans;
    }
};