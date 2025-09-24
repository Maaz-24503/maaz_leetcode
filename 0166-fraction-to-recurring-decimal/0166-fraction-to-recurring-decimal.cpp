class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        long long n = static_cast<long long>(numerator);
        long long d = static_cast<long long>(denominator);

        bool neg = (n < 0) ^ (d < 0);
        n = llabs(n);
        d = llabs(d);

        long long integerPart = n / d;
        long long rem = n % d;
        if (rem == 0) {
            return (neg && integerPart != 0 ? "-" : "") + to_string(integerPart);
        }

        string res = (neg ? "-" : "");
        res += to_string(integerPart) + ".";

        unordered_map<long long, int> pos;  
        while (rem != 0) {
            if (pos.count(rem)) {
                res.insert(pos[rem], "(");
                res.push_back(')');
                break;
            }
            pos[rem] = res.size();
            rem *= 10;
            res.push_back('0' + (rem / d));
            rem %= d;
        }
        return res;
    }
};
