class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        string ans = "";
        ans.reserve(n);
        long long val = 0;
        long long p = 1;
        for(int i = n - 1; i>=0; i--){
            if(s[i] == '0') ans += "0";
            else if(val + p <= k){
                ans += "1";
                val += p;
            }
            if(p < LLONG_MAX/20LL) p <<= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans.size();
    }
};