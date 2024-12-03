class Solution {
public:
    unordered_map<long long, int> memo;
    int recInd;
    long long denominator;
    string helper(long long remainder, int i){
        if(remainder == 0) return "";
        if(memo.find(remainder) != memo.end()){
            recInd = memo[remainder];
            return ")";
        }
        memo[remainder] = i;
        string ans = "";
        remainder *= 10;
        i++;
        while(remainder < denominator){
            i++;
            ans += "0";
            remainder *= 10;
        }
        long long pre = remainder/denominator;
        ans += to_string(pre);
        remainder %= denominator;
        return ans + helper(remainder, i);
    }
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        long long whole = abs(((long long)numerator)/((long long)denominator));
        long long remainder = abs((long long)numerator) % abs((long long)denominator);
        this->denominator = abs((long long)denominator);
        string frac = helper(remainder, 0);
        string ans = ((((long long)numerator)*((long long)denominator) > 0) ? "" : "-") + to_string(whole);
        
        if(remainder == 0) return ans;
        if(frac[frac.size()-1] == ')')
            frac.insert(frac.begin()+recInd, '(');
        return ans + "." + frac;
    }
};