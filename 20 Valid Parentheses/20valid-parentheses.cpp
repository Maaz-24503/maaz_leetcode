class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> opening;
        opening['('] = ')';
        opening['{'] = '}';
        opening['['] = ']';
        stack<char> stk;
        for(int i = 0; i<s.size(); i++){
            if(opening.find(s[i]) != opening.end())
                stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                if(opening[stk.top()] == s[i]) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};