class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> helper;
        unordered_map<char, int> freq;
        for(int i = 0; i<s.length(); i++){
            if(freq.find(s[i]) == freq.end()) freq[s[i]] = 1;
            else freq[s[i]]++;
        }
        for(auto& iter: freq){
            helper.push_back(make_pair(iter.second, iter.first));
        }
        s.clear();
        sort(helper.begin(), helper.end());
        reverse(helper.begin(), helper.end());
        for (const auto& entry : helper) {
            s.append(entry.first, entry.second);
        }
        return s;
    }
};