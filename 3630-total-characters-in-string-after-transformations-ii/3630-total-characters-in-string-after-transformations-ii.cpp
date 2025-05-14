class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;

    Matrix multiply(Matrix &a, Matrix &b) {
        int n = a.size();
        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
        return res;
    }

    Matrix matrixExpo(Matrix base, int exp) {
        int n = base.size();
        if (exp == 0) {
            Matrix identity(n, vector<long long>(n, 0));
            for (int i = 0; i < n; ++i) identity[i][i] = 1;
            return identity;
        }
        Matrix half = matrixExpo(base, exp / 2);
        Matrix result = multiply(half, half);

        if (exp % 2 == 1) {
            result = multiply(result, base);
        }

        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = 26;
        Matrix M(n, vector<long long>(n, 0)); 

        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int to = (i + j) % 26;
                M[to][i] = (M[to][i] + 1) % MOD;
            }
        }

        vector<long long> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        Matrix Mt = matrixExpo(M, t);

        vector<long long> finalFreq(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                finalFreq[i] = (finalFreq[i] + Mt[i][j] * freq[j]) % MOD;

        long long result = 0;
        for (int i = 0; i < 26; ++i) result = (result + finalFreq[i]) % MOD;
        return static_cast<int>(result);
    }
};
