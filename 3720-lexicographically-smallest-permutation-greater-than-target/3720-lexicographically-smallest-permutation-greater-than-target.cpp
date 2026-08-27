class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> f(26, 0);
        for (char c : s) f[c - 'a']++;

        auto smallestLarger = [](vector<int>& freq, int c) -> int {
            for (int i = c + 1; i < 26; i++)
                if (freq[i]) return i;
            return -1;
        };

        int k = 0;
        while (k < n && f[target[k] - 'a'] > 0) {
            f[target[k] - 'a']--;
            k++;
        }

        int pos;
        if (k == n) {
            pos = n - 1;
            f[target[pos] - 'a']++; 
        } else {
            pos = k; 
        }

        while (pos >= 0) {
            int g = smallestLarger(f, target[pos] - 'a');
            if (g != -1) {
                f[g]--;
                string ans = target.substr(0, pos);
                ans += char('a' + g);
                for (int i = 0; i < 26; i++)
                    if (f[i]) ans += string(f[i], 'a' + i);
                return ans;
            }
            if (pos - 1 >= 0) f[target[pos - 1] - 'a']++;
            pos--;
        }

        return "";
    }
};