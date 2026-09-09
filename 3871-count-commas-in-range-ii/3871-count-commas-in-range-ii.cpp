class Solution {
public:
    long long countCommas(long long n) {
        long long fifteen = 0, twelve = 0, nine = 0, six = 0, three = 0;
        string k = to_string(n);
        if(k.size() > 15) fifteen = 1;
        if(k.size() > 12) twelve = n - 999999999999LL - fifteen;
        if(k.size() > 9) nine = min(n, 999999999999LL) - 999999999LL;  
        if(k.size() > 6) six = min(n, 999999999LL) - 999999LL;  
        if(k.size() > 3) three = min(n, 999999LL) - 999LL;
        return 5*fifteen + 4*twelve + 3*nine + 2*six + three;  
    }
};