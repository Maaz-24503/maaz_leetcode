class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n > 0){
            if ((n & 3) == 3) {
                ans++;
                n++;
            } else if ((n & 1) == 1){
                ans++;
                n--;
            } else n >>= 1;
        }
        return ans;
    }
};