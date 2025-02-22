class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        long long p = n;
        if(p < 0){
            p *= -1;
            x = 1/x;
        }
        int q = p/2;
        double rec = myPow(x*x, q);
        if(p%2 == 1) return rec * x;
        else return rec;
    }
};