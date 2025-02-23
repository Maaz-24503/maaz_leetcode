class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int store = x;
        while(store != 0){
            if(rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
            rev = 10 * rev;
            rev += (store%10);
            store /= 10;
        }
        return rev;
    }
};