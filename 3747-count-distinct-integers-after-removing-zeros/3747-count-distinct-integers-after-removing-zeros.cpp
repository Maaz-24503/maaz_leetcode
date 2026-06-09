class Solution {
public:
    long long countDistinct(long long n) {
        string k = to_string(n);
        int m = k.size(); 
        vector<vector<vector<long long>>> memo(m + 1, vector<vector<long long>> (2, vector<long long> (2, -1)));
        function<long long(int, bool, bool)> dp = [&](int i, bool tight, bool nonZero) -> long long {
            if(i == m) return nonZero;
            if(memo[i][tight][nonZero] != -1) return memo[i][tight][nonZero];
            int limit = tight ? k[i] - '0' : 9;
            long long ans = 0LL;
            for(int j = 0; j <= limit; j++){
                if(j == 0){
                    if(!nonZero) ans += dp(i + 1, tight && (j == (k[i] - '0')), false); 
                } else {
                    ans += dp(i + 1,  tight && (j == (k[i] - '0')), true);
                }
            }
            return memo[i][tight][nonZero] = ans;
        };
        return dp(0, true, false);
    }
};