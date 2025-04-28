class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(3, vector<int> (2, 0)));
        // [index im at][no. transactions left][ive currently bought or not]
        // function<int(int,int,bool)> helper = [&](int i, int k, bool isBought){
        //     if(i == n || k == 0) return 0;
        //     if(memo[i][k][isBought] != -1) return memo[i][k][isBought];
        //     if(isBought)
        //         return memo[i][k][isBought] = max(prices[i] + helper(i+1, k-1, false), helper(i+1, k, true));
        //     else 
        //         return memo[i][k][isBought] = max(helper(i+1, k, false), helper(i+1, k, true) - prices[i]);
        // };
        for(int i = n-1; i>=0; i--){
            for(int k = 0; k<3; k++){
                for(int isBought = 0; isBought<2; isBought++){
                    if(k == 0) memo[i][k][isBought] = 0;
                    else if(isBought)
                        memo[i][k][isBought] = max(prices[i] + memo[i+1][k-1][false], memo[i+1][k][true]);
                    else 
                        memo[i][k][isBought] = max(memo[i+1][k][false], memo[i+1][k][true] - prices[i]);
                }
            }
        }
        return memo[0][2][false];
    }
};