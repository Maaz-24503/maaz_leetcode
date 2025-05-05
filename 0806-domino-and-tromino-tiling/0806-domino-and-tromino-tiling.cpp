class Solution {
public:
    int numTilings(int n) {
        vector<long long> f(n + 1, 1);  // ending complete
        vector<long long> g(n + 1, 0);  // ending with one empty
        int Mod = 1e9 + 7;
        for(int i = 2; i<=n; i++){
            f[i] = (f[i-1] + f[i-2] + 2*g[i-1]) % Mod;
            g[i] = (f[i-2] + g[i-1]) % Mod;
        }
        return f[n];
    }
};