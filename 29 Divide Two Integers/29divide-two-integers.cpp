class Solution {
public:
    int divide(int dividend, int divisor) {
        bool first = dividend > 0;
        bool second = divisor > 0;
        bool sign = first == second;
        long long ans = 0;
        long long dividend1 = abs(dividend);
        long long divisor1 = abs(divisor);
        if(divisor1 == 1) ans = dividend1;
        else
            while(dividend1 >= divisor1){
                ans++;
                dividend1 -= divisor1;
            }
        return sign ? (ans>INT_MAX?INT_MAX:ans) : (-ans<INT_MIN?INT_MIN:-ans); 
    }
};