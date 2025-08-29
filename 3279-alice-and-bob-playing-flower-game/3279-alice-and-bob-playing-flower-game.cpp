class Solution {
public:
    long long flowerGame(int n, int m) {
        long long nEven = n / 2, mEven = m / 2;
        long long nOdd = (n + 1) / 2, mOdd = (m + 1) / 2;
        return nOdd * mEven + mOdd * nEven;
    }
};