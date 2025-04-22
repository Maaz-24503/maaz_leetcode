class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<int> fact, invFact;

    long long modPow(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    void computeFactorials(int limit) {
        fact.resize(limit + 1);
        invFact.resize(limit + 1);
        fact[0] = 1;
        for (int i = 1; i <= limit; ++i)
            fact[i] = (1LL * fact[i - 1] * i) % MOD;

        invFact[limit] = modPow(fact[limit], MOD - 2); // Fermat's inverse
        for (int i = limit - 1; i >= 0; --i)
            invFact[i] = (1LL * invFact[i + 1] * (i + 1)) % MOD;
    }

    int comb(int a, int b) {
        if (b < 0 || b > a) return 0;
        return (1LL * fact[a] * invFact[b] % MOD) * invFact[a - b] % MOD;
    }

    vector<int> buildSieve(int maxValue) {
        vector<int> sieve(maxValue + 1);
        for (int i = 0; i <= maxValue; ++i) sieve[i] = i;
        for (int i = 2; i * i <= maxValue; ++i) {
            if (sieve[i] == i) {
                for (int j = i * i; j <= maxValue; j += i) {
                    if (sieve[j] == j) sieve[j] = i;
                }
            }
        }
        return sieve;
    }

    unordered_map<int, int> factorize(int x, const vector<int>& sieve) {
        unordered_map<int, int> factors;
        while (x > 1) {
            int sp = sieve[x];
            factors[sp]++;
            x /= sp;
        }
        return factors;
    }

public:
    int idealArrays(int n, int maxValue) {
        computeFactorials(n + 13); 
        vector<int> sieve = buildSieve(maxValue);

        long long res = 0;
        for (int i = 1; i <= maxValue; ++i) {
            long long ways = 1;
            auto factors = factorize(i, sieve);
            for (auto& [prime, exp] : factors) {
                ways = (ways * comb(n - 1 + exp, exp)) % MOD;
            }
            res = (res + ways) % MOD;
        }
        return (int)res;
    }
};
