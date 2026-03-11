class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int k = 0;
        while(k <= n)
            k = (k << 1) | 1; 
        k >>= 1;
        return (~n) & k;
    }
};