class Solution {
private:
    vector<int> memo;
    int helper(int n){
        if(n <= 1) return 1;
        if(memo[n] != -1) return memo[n];
        int ways = 0;
        for(int i = 1; i<=n; i++){
            ways += helper(i-1)*helper(n-i);
        }
        return memo[n] = ways;
    }
public:
    int numTrees(int n) {
        memo.resize(n+1, -1);
        return helper(n);
    }
};