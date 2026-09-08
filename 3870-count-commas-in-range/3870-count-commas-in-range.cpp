class Solution {
public:
    int countCommas(int n) {
        int l = to_string(n).size();
        if(l < 4) return 0;
        else return n - 999;
    }
};