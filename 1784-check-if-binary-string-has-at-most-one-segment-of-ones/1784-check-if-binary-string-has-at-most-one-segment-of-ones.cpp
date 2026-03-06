class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool zeroSeen = false;
        for(int i = 0; i < n; i++){
            if(zeroSeen && s[i] == '1') return false;
            if(!zeroSeen && s[i] == '0') zeroSeen = true;
        }
        return true;
    }
};