class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<pair<char, int>> occ;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(vowels.count(s[i])) occ.push_back({s[i], i});
        }
        for(int i = 0; i<occ.size(); i++){
            s[occ[occ.size() - i - 1].second] = occ[i].first;
        }
        return s;
    }
};