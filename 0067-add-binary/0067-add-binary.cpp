class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size()) swap(a, b);
        int n = a.size();
        reverse(b.begin(), b.end());
        b += string(n - b.size(), '0');
        reverse(b.begin(), b.end());
        int rem = 0;
        string ans = "";
        for(int i = n - 1; i >= 0; i--){
            if(a[i] == '1' && b[i] == '1'){
                if(rem) ans += "1";
                else ans += "0";
                rem = 1;
            } else if(a[i] == '1' || b[i] == '1'){
                if(rem){
                    ans += "0";
                    rem = 1;
                } else {
                    ans += "1";
                    rem = 0;
                }
            } else {
                if(rem) ans += "1";
                else ans += "0";
                rem = 0;
            }
        }
        if(rem) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};