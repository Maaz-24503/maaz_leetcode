class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int l = 0, r = 0;
        while(l<word1.size() && r<word2.size()){
            ans += word1[l++];
            ans += word2[r++];
        }
        if(l < word1.size()) ans += word1.substr(l);
        if(r < word2.size()) ans += word2.substr(r);
        return ans;
    }
};