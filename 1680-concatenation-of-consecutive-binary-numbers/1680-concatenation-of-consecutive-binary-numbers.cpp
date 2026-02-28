class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0LL;
        int bits = 0;
        int MOD = 1e9 + 7;
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0) bits++;  // basically means i is a pwr of 2;
            ans = ((ans<<bits) + i) % MOD; 
        }
        return ans;
    }
};