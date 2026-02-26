class Solution {
public:
    int numSteps(string s) {
        int ans = 0, carry = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            if ((s[i] - '0') + carry == 1) {
                ans += 2;
                carry = 1;
            } else ans += 1;
        }
        
        return ans + carry;
    }
};