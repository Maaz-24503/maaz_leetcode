class Solution {
private:
    string s;
    int limit;

    long long toDec(string num) {
        long long result = 0;
        for (char c : num) {
            int value = c - '0';
            result = result * (limit+1) + value;    // if its dig 4, its base 5 bcz 0->4
        }
        return result+1;        // Count 0 for this base
    }

    long long lessThan(long long lim){
        if (lim < stoll(s)) return 0;
        string strLim = to_string(lim);
        int prefixLength = strLim.size() - s.size();
        long long newLim = 0;
        if (prefixLength > 0) newLim = stoll(strLim.substr(0, prefixLength));
        if (strLim.substr(prefixLength) < s) newLim--;
        strLim = to_string(newLim);
        int i = 0;
        while(i < strLim.size() && strLim[i] - '0' <= limit) i++;
        if(i != strLim.size()){
            while(i < strLim.size()){
                strLim[i] = limit + '0';
                i++;
            }
        }
        return toDec(strLim);
    }


public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int n = s.size();
        for(char& c: s) if(c > '0' + limit) return 0LL;
        this->limit = limit;
        this->s = s;
        return lessThan(finish) - lessThan(start-1);
    } 
};