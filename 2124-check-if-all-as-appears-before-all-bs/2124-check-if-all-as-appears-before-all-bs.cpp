class Solution {
public:
    bool checkString(string s) {
        bool bSeen = false;
        for(char &c : s){
            if(c == 'a' && bSeen) return false;
            if(c == 'b') bSeen = true;
        }
        return true;
    }
};