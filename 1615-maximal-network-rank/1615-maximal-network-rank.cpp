class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> check(n);
        vector<int> count(n, 0);
        for(int i = 0; i < roads.size(); i++){
            check[roads[i][0]].insert(roads[i][1]);
            check[roads[i][1]].insert(roads[i][0]);
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int curr = count[i] + count[j];
                if(check[i].find(j) != check[i].end()) curr--;
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};