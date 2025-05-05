class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0; i<n; i++) freq[s[i] - 'a']++;
        stack<char> st;
        vector<bool> isUsed(26, false);
        for(int i = 0; i<n; i++){
            if(!isUsed[s[i] - 'a']){
                while(!st.empty() && freq[st.top() - 'a'] > 0 && st.top() >= s[i]){
                    isUsed[st.top() - 'a'] = false;
                    st.pop();
                }
                isUsed[s[i] - 'a'] = true;
                st.push(s[i]);
            }
            freq[s[i] - 'a']--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};