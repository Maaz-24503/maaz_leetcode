class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        string pri = x > y ? "ab" : "ba";
        string sec = x > y ? "ba" : "ab";
        stack<char> st;
        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(s[i]);
            else{
                string curr = string(1, st.top()) + s[i];
                if(curr == pri){
                    ans += max(x, y);
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        string rem = "";
        while(!st.empty()){
            rem += string(1, st.top());
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        int m = rem.size();
        for(int i = 0; i<m; i++){
            if(st.empty()) st.push(rem[i]);
            else{
                string curr = string(1, st.top()) + rem[i];
                if(curr == sec){
                    ans += min(x, y);
                    st.pop();
                }
                else {
                    st.push(rem[i]);
                }
            }
        }
        return ans;
    }
};