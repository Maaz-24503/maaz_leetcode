class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), leastCost = INT_MAX;
        vector<int> factorCount(n, 0);
        for(int i = 0; i < n; i++){
            leastCost = min(leastCost, items[i][1]);
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                if(items[j][0] % items[i][0] == 0) factorCount[i]++;
            }
        }
        // memo[i][j] -> max no. items we can pick using only first time picks uptil item i with budget j
        vector<vector<int>> memo(n + 1, vector<int> (budget + 1, -1));
        function<int(int,int)> dp = [&](int i, int j) -> int {
            if(i < 0) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            if(items[i][1] > j) return memo[i][j] = dp(i - 1, j);
            return memo[i][j] = max(dp(i - 1, j), factorCount[i] + 1 + dp(i - 1, j - items[i][1]));
        };
        int ans = 0; 
        for(int j = 0; j < budget + 1; j++){
            ans = max(ans, dp(n - 1, j) + (budget - j) / leastCost);
        }
        return ans;
    }
};