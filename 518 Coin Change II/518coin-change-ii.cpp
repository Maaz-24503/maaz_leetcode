class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount+1, 0));
        for(int i = 0; i<n; i++){
            memo[i][0] = 1;
        }
        for(int i = 0; i<n; i++){
            for(int j = 1; j<amount+1; j++){
                if(i != 0) memo[i][j] += memo[i-1][j];
                if(coins[i] <= j) memo[i][j] += memo[i][j - coins[i]];
            }
        }
        return memo[n-1][amount];
    }
};