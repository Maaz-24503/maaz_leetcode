class Solution {
private:
    int mod;

    long long modPow(long long b, long long p){
        if(p == 0) return 1;
        long long rec = modPow(b, p/2);
        if(p % 2 == 1) return (((rec*rec)%mod)*b)%mod;
        return (rec*rec)%mod;
    }

    int modMul(long long a, long long b){
        return static_cast<int>((a*b)%mod);
    }

public:
    int countGoodNumbers(long long n) {
        mod = 1e9 + 7;
        long long odd = n/2;
        long long even = n - odd;
        odd = modPow(4, odd);
        even = modPow(5, even);
        return modMul(odd, even);
    }
};
