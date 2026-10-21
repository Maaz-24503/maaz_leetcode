class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());
        if(s == t) return 0;
        if(s.size() < 3) return -1;
        bool isStartFlipped = false;
        bool isEndFlipped = false;
        if(t[n - 1] == s[0] && (t[n - 1] != t[n - 2])) isStartFlipped = true;
        if(t[0] == s[n - 1] && (t[0] != t[1])) isEndFlipped = true;
        if(isStartFlipped && isEndFlipped) return 3;
        if(t[0] == s[0] || t[n - 1] == s[n - 1]) return 1;
        return 2;
    }
};