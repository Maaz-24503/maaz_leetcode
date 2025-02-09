class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<int> prices;

    int helper(int k, int i, bool bought){
        if(i == prices.size() || k == 0) return 0;
        if(memo[k][i][bought] != -1) return memo[k][i][bought];
        if(!bought) return memo[k][i][bought] = max(-prices[i] + helper(k, i+1, true), helper(k, i+1, false));
        return memo[k][i][bought] = max(prices[i] + helper(k-1, i+1, false), helper(k, i+1, true));
    }

    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        memo.resize(k+1, vector<vector<int>>(prices.size()+1, vector<int>(2, -1)));
        return helper(k, 0, false);
    }
};