class Solution {
private:
    vector<int> memo;

    int fact(int n){
        if(n == 0) return 1;
        return n * fact(n-1);
    }

    int helper(int n){
        if(n == 0) return 1;
        if(memo[n] != -1) return memo[n];
        return memo[n] = (9 * (fact(9)/fact(9 - (n-1)))) + helper(n-1);
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        memo.resize(n + 1, -1);
        return helper(n);
    }
};