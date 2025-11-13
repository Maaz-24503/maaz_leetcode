class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> star;
        stack<int> st;
        for(int i = 0; i<n; i++){
            if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
            else if(s[i] == '*') star.push(i);
            else st.push(i);
        }
        if(star.size() < st.size()) return false;
        while(!st.empty()){
            if(st.top() < star.top()){
                st.pop();
                star.pop();
            }
            else return false;
        }
        return true;
    }
};