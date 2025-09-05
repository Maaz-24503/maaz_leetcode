class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2 == 0) return __builtin_popcount(num1);
        long long p = num1;
        for(int i = 1; i<=60; i++){
            p -= num2;
            int left = __builtin_popcountll(p);
            if(p > 0 && left <= i && p >= i) return i;
        }
        return -1;
    }
};