class Solution {
private:
    char helper(int n, int k){
        if(n == 1) return '0';
        long long len = (1LL << n) - 1;
        if(k == len / 2) return '1';
        if(k < len / 2) return helper(n - 1, k);
        int prevLen = len / 2;
        // int prevInd = prevLength - (k - prevLength - 1) - 1;
        int prevInd = 2 * prevLen - k;
        int rec = helper(n - 1, prevInd);
        return rec == '0' ? '1' : '0';
    }
public:
    // length(n) = 2*length(n - 1) + 1
    char findKthBit(int n, int k) {
        return helper(n, k - 1);
    }
};