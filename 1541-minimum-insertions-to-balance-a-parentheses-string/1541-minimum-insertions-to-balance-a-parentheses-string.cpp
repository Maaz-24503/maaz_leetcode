class Solution {
public:
    int minInsertions(string s) {
        vector<bool> st;    // true basically means both closing brackets left, false means one done one left :P
        int ans = 0;
        for(const char &c : s){
            if(c == '(') {
                if(st.empty()) st.push_back(true);
                else {
                    if(st.back()) st.push_back(true);
                    else {
                        ans++;
                        st.pop_back();
                        st.push_back(true);
                    }
                } 
            } else {
                if(st.empty()) {
                    ans++;
                    st.push_back(false);
                } else {
                    if(st.back()) st[st.size() - 1] = false;
                    else st.pop_back();
                }
            }
        }
        while(!st.empty()) {ans += st.back() ? 2 : 1; st.pop_back();}
        return ans;
    }
};