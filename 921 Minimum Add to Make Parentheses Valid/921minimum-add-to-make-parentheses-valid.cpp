class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<bool> stk;
        int counter = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(') stk.push(1);
            else{
                if(stk.empty()) counter++;
                else stk.pop();
            }
        }
        return counter + stk.size();
    }
};