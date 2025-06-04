class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        set<string> words;
        for(int i = 0; i<n; i++){
            string temp = word.substr(i, min(word.size() - numFriends + 1, word.size() - i));
            words.insert(temp);
        }
        return *(words.rbegin());
    }
};