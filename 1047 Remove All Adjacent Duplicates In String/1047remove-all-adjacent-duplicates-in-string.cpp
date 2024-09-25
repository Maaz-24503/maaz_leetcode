class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> x;
        for (int i = 0; i < s.length(); i++) {
            if(x.empty()) x.push(s[i]);
            else{
                if(x.top() == s[i]) x.pop();
                else x.push(s[i]);
            }
        }
        string ans = "";
        while(!x.empty()){
            ans = x.top() + ans;
            x.pop();
        }
        return ans;
    }
};