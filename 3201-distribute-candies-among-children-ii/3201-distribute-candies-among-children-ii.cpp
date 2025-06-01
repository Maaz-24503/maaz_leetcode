class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0LL;
        for(int i = 0; i<=limit; i++) ans += max(0LL, 1LL + (min(limit, n - i) * 2) - (n - i));
        return ans;
    }
};