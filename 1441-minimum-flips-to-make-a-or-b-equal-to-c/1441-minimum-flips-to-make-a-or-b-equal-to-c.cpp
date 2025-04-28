class Solution {
public:
    int minFlips(int a, int b, int c) {
        long long mask = 1;
        int ans = 0;
        while(mask <= a || mask <= b || mask <= c){
            bool aOn = (a&mask) != 0, bOn = (b&mask) != 0, cOn = (c&mask) != 0;
            if(cOn && !aOn && !bOn) ans++;
            else if(!cOn){
                if(aOn) ans++;
                if(bOn) ans++;
            }
            mask <<= 1;
        }
        return ans;
    }
};