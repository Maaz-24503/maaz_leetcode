class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        function<bool(int, int)> isValid = [&s](int i, int j) -> bool {
            vector<int> f(26, 0);
            for(int k = i; k <= j; k++) f[s[k] - 'a']++;
            for(int k = 0; k < 26; k++) if(f[k] > 2) return false;
            return true;
        };
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(isValid(i, j))
                    ans = max(ans, j - i + 1);
        return ans;
    }
};