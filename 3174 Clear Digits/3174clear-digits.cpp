class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] <= '9' && s[i] >= '0') st.pop();
            else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};