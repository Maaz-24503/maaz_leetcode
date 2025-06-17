class Solution {
private:
    int n, m, k;
    int MOD = 1000000007;
    vector<int> fact, factInv;

    int powMod(long long k, int p){
        if(p == 0) return 1;
        long long half = powMod(k, p/2);
        if(p % 2) return (((half * half) % MOD) * k) % MOD;
        else return (half * half) % MOD;
    }

    void preComp(){
        // Calculate factorial first
        fact.resize(n + 1, 1);
        for(int i = 1; i<=n; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;

        // Now inverse, a lot more complex, use fermats little theorem
        factInv.resize(n + 1, 1);
        factInv[n] = powMod(fact[n], MOD - 2); // inverse of n!

        for (int i = n - 1; i >= 0; i--) factInv[i] = (1LL * factInv[i + 1] * (i + 1)) % MOD;
    }

public:
    int countGoodArrays(int n, int m, int k) {
    this->n = n;
    this->m = m;
    this->k = k;
    preComp();

    int uneq = n - k;

    // (n-1 C uneq - 1)
    int barWays = (1LL * fact[n - 1] * factInv[uneq - 1]) % MOD;
    barWays = (1LL * barWays * factInv[k]) % MOD;
    int assignments = (1LL * m * powMod(m - 1, uneq - 1)) % MOD;
    return (1LL * barWays * assignments) % MOD;
    }
};