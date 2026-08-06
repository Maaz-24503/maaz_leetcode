class Solution {
public:
    int smallestNumber(int n, int t) {
        function<bool(int)> check = [t](int k) -> bool{
            int prod = 1;
            while(k > 0){
                prod *= k % 10;
                k /= 10;
            }
            return prod % t == 0;
        };
        for(int i = n; i < 1e5; i++){
            if(check(i)) return i;
        }
        return -1;
    }
};