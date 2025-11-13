class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> longest(26, 0);
        vector<char> prev(26, 'z');
        for(int i = 1; i < 26; i++) prev[i] = 'a' + i - 1;
        function<void(int, int)> upd = [&](int i, int r) -> void {
            for(int k = 0; k<26; k++)
                longest[(k + i) % 26] = max(longest[(k + i) % 26], r - k);
        };
        for(int i = 0; i<n; i++){
            int run = 1;
            while(run + i < n && s[run + i - 1] == prev[s[run + i] - 'a']) run++;
            upd(s[i] - 'a', run);
            i = i + run - 1;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) ans += longest[i];
        return ans;
    }
};