class Solution {
public:
    bool isValid(string s) {
       int n = s.size();
       vector<char> st;
       unordered_map<char,char> brack {
        {'}', '{'},
        {')', '('},
        {']', '['}
       }; 
       for(const char &c : s){
        if(brack.find(c) == brack.end()){
            st.push_back(c);
        } else {
            if(st.empty() || st.back() != brack[c]) return false;
            st.pop_back();
        }
       }
       return st.empty();
    }
};