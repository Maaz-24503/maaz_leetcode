class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0; i<n; i++) freq[s[i] - 'a']++;
        stack<char> st;
        vector<bool> used(26, false);
        for (char c : s) {
            freq[c - 'a']--;

            if (used[c - 'a']) continue;

            while (!st.empty() && c < st.top() && freq[st.top() - 'a'] > 0) {
                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            used[c - 'a'] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};