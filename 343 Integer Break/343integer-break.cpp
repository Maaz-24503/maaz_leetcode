class Solution {
public:
    vector<int> memo;
    int helper(int n){
        if(memo[n]!= -1) return memo[n];
        if(n == 0) return 1;
        int maxi = 0;
        for(int i = 1; i<=n; i++){
            maxi = max(maxi, i * helper(n-i)); 
        }
        return memo[n] = maxi;
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        memo = vector<int> (n+1,-1);
        return helper(n);
    }
};