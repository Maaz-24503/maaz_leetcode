class Solution {
private:
    string s;
    long long suff;
    int limit;

    long long lessThan(long long lim){
        if(lim < suff) return 0;
        lim = lim < 0 ? 0 : lim;
        string strlim = to_string(lim);
        vector<vector<long long>> memo(2 ,vector<long long>(strlim.size()+1, -1));
        function<long long(int,bool)> helper = [&](int i, bool strict){
            if(i == strlim.size() - s.size()) {
                return strict ? (s <= strlim.substr(i) ? 1LL : 0LL) : 1LL;
            }
            if(memo[strict][i] != -1) return memo[strict][i];
            if(i == 0){
                int poss = min(strlim[i] - '0', limit);
                return memo[strict][i] = strlim[i] - '0' == poss ? (poss * helper(i+1, false)) + helper(i+1, true) :
                                        (poss+1) * helper(i+1, false);
            }
            if(strict){
                int poss = min(strlim[i] - '0', limit);
                return memo[strict][i] = strlim[i] - '0' == poss ? (poss * helper(i+1, false)) + helper(i+1, true) :
                                        (poss+1) * helper(i+1, false);
            }
            else return memo[strict][i] = (limit+1) * helper(i+1, false);
        };
        return helper(0, true);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int n = s.size();
        for(char& c: s) if(c > '0' + limit) return 0LL;
        suff = stoll(s);
        this->limit = limit;
        this->s = s;
        return lessThan(finish) - lessThan(start-1);
    }
};