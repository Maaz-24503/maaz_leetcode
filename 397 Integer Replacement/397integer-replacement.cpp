class Solution {
public:
    unordered_map<int, int> memo;
    long long lim;
    int helper(long long n){
        // cout<<n<<endl;
        if(n == lim) return INT_MAX;
        if(n == 1) return 0;
        if(memo.find(n) != memo.end()) return memo[n];
        if(n % 2 == 0) return memo[n] = 1 + helper(n/2);
        return memo[n] = 1 + min(helper(n-1), helper(n+1));
    }
    int integerReplacement(int n) {
        lim = ((long long)n)+2;
        return helper(n);
    }
};