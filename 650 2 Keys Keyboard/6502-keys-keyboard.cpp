class Solution {
public:
    long long helper(int curr, int jump, vector<vector<long long>>& memo, int n){
        if(curr == n) return 0;
        if(curr > n) return INT_MAX;
        if(memo[curr][jump] != -1) return memo[curr][jump];
        if(jump == 0) return memo[curr][jump] = 1 + (long long)helper(curr + jump, curr + jump, memo, n);
        return memo[curr][jump] = 1 + min((long long)1 + helper(curr + jump, curr + jump, memo, n), (long long)helper(curr + jump, jump, memo, n));
    }
    int minSteps(int n) {
        vector<vector<long long>> memo(n+1, vector<long long>(n+1, -1));
        return helper(1, 0, memo, n);
    }
};