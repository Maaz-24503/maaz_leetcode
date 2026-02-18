class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool isOn = (1 & n) == 1;
        long long mask = 2;
        while(mask <= n) {
            if(((mask & n) != 0) == isOn) return false;
            mask <<= 1; isOn = !isOn;
        }
        return true;
    }
};