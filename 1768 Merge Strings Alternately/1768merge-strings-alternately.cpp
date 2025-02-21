class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int maxi = max(word1.size(), word2.size());
        int lim = min(word1.size(), word2.size());
        for(int i = 0; i<lim; i++){
            ans = ans + word1[i] + word2[i];
        }
        if(maxi > word1.size()) ans += word2.substr(lim, maxi - lim);
        if(maxi > word2.size()) ans += word1.substr(lim, maxi - lim);
        return ans;
    }
};