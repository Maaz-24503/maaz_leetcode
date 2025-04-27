class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int> (2, -1));
        function<int(int,bool)> helper = [&](int i, bool isBought){
            if(i == n) return 0;
            if(memo[i][isBought] != -1) return memo[i][isBought];
            if(isBought){
                int selling = prices[i] + helper(i + 1, false);
                int keeping = helper(i + 1, true);
                return memo[i][isBought]  = max(selling, keeping);
            }
            else{
                int buying = helper(i + 1, true) - (prices[i] + fee);
                int leaving = helper(i + 1, false);
                return memo[i][isBought] = max(leaving, buying);
            }
        };
        return helper(0, 0);
    }
};