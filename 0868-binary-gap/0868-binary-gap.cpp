class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, curr = 0, ans = 0;
        long long mask = 1;
        while(mask <= n){
            if((mask & n) != 0){
                if(prev == -1) {
                    prev = curr;
                } else {
                    ans = max(ans, curr - prev);
                    prev = curr;
                }
            }
            mask <<= 1;
            curr++;
        }
        return ans;
    }
};