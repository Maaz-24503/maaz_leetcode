class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int n = word1.size();
        unordered_map<char, int> map1, map2;
        for(int i = 0; i<n; i++){
            map1[word1[i]]++;
            map2[word2[i]]++;
        }
        for(auto [ch, freq] :map1) if(map2.find(ch) == map2.end()) return false;
        vector<int> fr1, fr2;
        for(auto [ch, freq] :map1) fr1.push_back(freq);
        for(auto [ch, freq] :map2) fr2.push_back(freq);
        sort(fr1.begin(), fr1.end());
        sort(fr2.begin(), fr2.end());
        if(fr1.size() != fr2.size()) return false;
        for(int i = 0; i<fr1.size(); i++) if(fr1[i] != fr2[i]) return false;
        return true;
    }
};