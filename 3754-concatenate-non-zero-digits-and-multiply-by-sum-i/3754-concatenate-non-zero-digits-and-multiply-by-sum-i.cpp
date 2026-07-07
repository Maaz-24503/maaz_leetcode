class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0LL, sum = 0LL;
        long long curr = 1, desCurr = 1;
        while(curr <= n){
            long long dig = (n % (curr*10)) / curr;
            sum += dig;
            if(dig != 0){
                x += desCurr * dig;
                desCurr *= 10;
            } 
            curr *= 10;
        }
        return x * sum;
    }
};