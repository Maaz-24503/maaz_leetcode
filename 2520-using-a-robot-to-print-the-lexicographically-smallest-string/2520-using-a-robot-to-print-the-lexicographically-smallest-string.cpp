class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string ans = "";
        stack<int> t;
        vector<int> freq(26, 0);
        function<bool(int)> isValid = [&](int c){
            for(int i = 0; i<c; i++) if(freq[i]) return false;
            return true;
        };
        for(int i = 0; i<n; i++){
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i<n; i++){
            t.push(s[i] - 'a');
            freq[s[i] - 'a']--;
            while(!t.empty() && isValid(t.top())){
                ans += string(1, 'a' + t.top());
                t.pop();
            }
        }
        return ans;
    }
};