class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int curr = 0;
        // cout<<s<<endl;
        while(curr<s.size()){
            if(s[curr] >= '0' && s[curr] <= '9'){
                int end = curr;
                while(s[end] != '[') end++;
                int freq = stoi(s.substr(curr, end - curr));
                end++;
                curr = end;
                // cout<<" freq: "<<freq<<" curr: "<<curr;
                int count = 1;
                while(count>0){
                    if(s[end] == ']') count--;
                    else if(s[end] == '[') count++;
                    end++;
                }
                string tok = decodeString(s.substr(curr, end - curr - 1));
                for(int i = 0; i<freq; i++) ans += tok;
                curr = end;
            }
            else{
                int end = curr;
                while(end < s.size() && !(s[end] >= '0' && s[end] <= '9')) end++;
                ans += s.substr(curr, end - curr);
                curr = end;
            }
        }
        return ans;
    }
};