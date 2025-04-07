class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int curr = 0;
        for(int i = 0; i<k; i++) if(vowels.find(s[i]) != vowels.end()) curr++;
        int maxi = curr;
        for(int i = 0; i<n-k; i++){
            if(vowels.find(s[i]) != vowels.end()) curr--;
            if(vowels.find(s[i + k]) != vowels.end()) curr++;
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};