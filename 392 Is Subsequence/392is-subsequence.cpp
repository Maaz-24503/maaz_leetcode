class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        for(int i = 0; i<t.length(); i++){
            if(left == s.length()) return true;
            if(t[i] == s[left]) left++;
        }
        if(left == s.length()) return true;
        else return false;
    }
};