class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31};     // all possible under 32 bits
        function<int(int)> numBits = [](int num) -> int {
            long long mask = 1LL;
            int ans = 0;
            while(mask <= num){
                if((mask & num) != 0) ans++;
                mask <<= 1;
            }
            return ans;
        };
        int ans = 0;
        for(int num = left; num <= right; num++){
            if(find(primes.begin(), primes.end(), numBits(num)) != primes.end()) ans++;
        }
        return ans;
    }
};