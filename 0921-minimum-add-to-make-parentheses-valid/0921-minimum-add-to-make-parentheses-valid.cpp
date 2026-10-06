class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, ans = 0;
        for(const char &c : s){
            if(c == '(') open++;
            else {
                if(open) open--;
                else ans++;
            }
        }
        return open + ans;
    }
};