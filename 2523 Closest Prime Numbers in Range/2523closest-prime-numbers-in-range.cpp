class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[1] = false;
        for (int i = 2; i * i < right + 1; i++) {
            long long curr = i * 2;
            if (!isPrime[i])
                continue;
            while (curr <= right) {
                isPrime[curr] = false;
                curr += static_cast<int>(i);
            }
        }
        vector<int> ans{-1, -1};
        int minDiff = INT_MAX;
        int currPrime = -1;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                if (currPrime == -1)
                    currPrime = i;
                else {
                    if (minDiff > i - currPrime) {
                        ans = {currPrime, i};
                        minDiff = i - currPrime;
                    }
                    currPrime = i;
                }
            }
        }
        return ans;
    }
};