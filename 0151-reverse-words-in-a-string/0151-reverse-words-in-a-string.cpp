class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss{s};
        string word;
        while(ss>>word) words.push_back(word);
        reverse(words.begin(), words.end());
        string ans = "";
        for(auto& item : words) ans += item + " ";
        return ans.substr(0, ans.size()-1);
    }
};