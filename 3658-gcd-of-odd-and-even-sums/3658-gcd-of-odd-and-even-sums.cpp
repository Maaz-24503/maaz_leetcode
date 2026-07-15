class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        function<int(int, int)> gcd = [&](int a, int b) -> int {
            if(a % b == 0) return b;
            return gcd(b, a % b);
        };
        int sumOdd = 0, sumEven = 0;
        for(int i = 1; i <= 2 * n; i++){
            if(i % 2) sumOdd += i;
            else sumEven += i;
        }
        return gcd(sumEven, sumOdd);
    }
};