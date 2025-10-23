class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        if(n == 2) return s[0] == s[1];
        string next = string(n - 1, 'a');
        for(int i = 0; i < n - 1; i++)
            next[i] = (((s[i] - '0') + (s[i + 1] - '0')) % 10) + '0';
        return hasSameDigits(next);
    }
};