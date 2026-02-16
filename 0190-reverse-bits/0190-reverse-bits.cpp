class Solution {
public:
    int reverseBits(int n) {
        string num = "";
        for(int i = 0; i < 32; i++){
            if((n & 1) == 1) num += "1";
            else num += "0";
            n >>= 1;
        }
        cout<<num;
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            ans <<= 1;
            if(num[i] == '1') ans |= 1;
        }
        return ans;
    }
};