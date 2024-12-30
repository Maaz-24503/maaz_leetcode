class Solution {
public:
    int low, high, zero, one;
    int mod = 1000000007;
    vector<int> memo;

    int helper(int i){
        if(i > high) return 0;
        if(memo[i] != -1) return memo[i];
        long long subProb = helper(i+zero);
        subProb += helper(i+one);
        subProb %= mod;
        return memo[i] = (i >= low) ? (subProb + 1)%mod : subProb;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        this->high = high;
        this->low = low;
        this->zero = zero;
        this->one = one;
        memo.resize(high+1, -1);
        return helper(0);
    }
};