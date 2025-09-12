class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        for(int i = 0; i<s.size(); i++) 
            if(vowels.find(s[i]) != vowels.end()) count++;
        return count ? true : false;
    }
};