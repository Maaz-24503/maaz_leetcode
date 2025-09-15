class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss{text};
        string curr;
        vector<bool> broken(26, false);
        for(char &c : brokenLetters) broken[c - 'a'] = true;
        int ans = 0;
        while(ss >> curr){
            bool check = false;
            for(char &c : curr)
                if(broken[c - 'a']) {
                    check = true;
                    break;
                }
            if(!check) ans++;
        }
        return ans;
    }
};