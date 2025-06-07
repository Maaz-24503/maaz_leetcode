class Solution {
public:
    string clearStars(string s) {
        string ans = "";
        int n = s.size();
        vector<bool> exists(n, true);
        vector<stack<int>> st(26);

        for(int i = 0; i<n; i++){
            if(s[i] == '*') 
                exists[i] = false;
        }
        for(int i = 0; i<n; i++){
            if(s[i] == '*'){
                for(int j = 0; j<26; j++){
                    if(!st[j].empty()){
                        exists[st[j].top()] = false;
                        st[j].pop();
                        break;
                    }
                }
            }
            else st[s[i] - 'a'].push(i);
        }
        for(int i = 0; i<n; i++) if(exists[i]) ans += string(1, s[i]);
        return ans;
        
    }
};