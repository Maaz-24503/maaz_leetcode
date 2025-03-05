class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<bool> isPrime(n, true);
        isPrime[1] = false;
        int ans = 0;
        for(int i = 2; i<n; i++){
            if(isPrime[i]){
                ans++;
                long long curr = 2*i;
                while(curr < n){
                    isPrime[curr] = false;
                    curr += (i+0LL);
                }
            }
        }
        return ans;
    }
};