class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int zeros = 0, ones = 0, ans = 0;
        bool isOne = s[0] == '1';
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(isOne){
                    zeros = 1;
                    isOne = false;
                } else {
                    zeros++;
                }
                if(zeros <= ones) ans++;
            } else {
                if(isOne) {
                    ones++;
                } else {
                    ones = 1;
                    isOne = true;
                }
                if(ones <= zeros) ans++;
            }
        }
        return ans;
    }
};