class Solution {
public:
    int smallestNumber(int n) {
        long long mask = 1;
        while(mask - 1LL < n) mask <<= 1;
        return mask - 1LL;
    }
};