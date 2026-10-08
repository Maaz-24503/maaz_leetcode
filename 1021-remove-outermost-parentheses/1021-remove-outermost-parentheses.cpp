class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int opening = 0;
        for(const char &c : s){
            if(c == '('){
                if(opening != 0) ans += "(";
                opening++;
            } else {
                if(opening != 1) ans += ")";
                opening--;
            }
        }
        return ans;
    }
};