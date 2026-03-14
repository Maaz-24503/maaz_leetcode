class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> words{"a", "b", "c"};
        for(int i = 0; i < n - 1; i++){
            vector<string> temp;
            for(int j = 0; j < words.size(); j++){
                char last = words[j][words[j].size() - 1];
                if(last != 'a') temp.push_back(words[j] + "a");
                if(last != 'b') temp.push_back(words[j] + "b");
                if(last != 'c') temp.push_back(words[j] + "c");
            }
            words = temp;
        }
        sort(words.begin(), words.end());
        return k > words.size() ? "" : words[k - 1];
    }
};