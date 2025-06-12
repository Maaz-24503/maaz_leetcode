class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        function<int(int, int)> gcd = [&](int a, int b){
            if(b % a == 0) return a;
            return gcd(b % a, a);
        };
        int GCD = gcd(min(x, y), max(x, y));
        if(target % GCD) return false;
        return true;
    }
};