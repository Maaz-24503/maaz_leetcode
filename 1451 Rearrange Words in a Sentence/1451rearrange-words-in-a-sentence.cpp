class Solution {
public:
    static bool customComparison(pair<string, int> a, pair<string, int> b){
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
        return a.second < b.second;
    }

    string arrangeWords(string text) {
        vector<pair<string, int>> sentence;
        text[0] -= ('A' - 'a');
        stringstream ss(text);
        string word;
        int k = 0;
        while(ss>>word){
            sentence.push_back({word, k});
            k++;
        }
        sort(sentence.begin(), sentence.end(), customComparison);
        string ans = sentence[0].first;
        ans[0] += ('A' - 'a');
        for(int i = 1; i<sentence.size(); i++){
            ans += " "+sentence[i].first;
        }
        return ans;
    }
};