class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        vector<long long> f(n + 1, 0);
        vector<long long> g(n + 1, 0);
        f[0] = 1, f[1] = 1;
        for(int i = 2; i<=n; i++){
            g[i] = (g[i-1] + f[i-2]) % mod;
            f[i] = (2*g[i - 1] + f[i - 1] + f[i - 2]) % mod;
        }
        return f[n];
    }
};