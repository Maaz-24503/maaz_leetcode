class Solution {
public:
    int sz;
    string pre;
    bool comp(string tbc){
        for(int i = 0; i<sz; i++) if(pre[i] != tbc[i]) return false;
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        this->sz = searchWord.size();
        this->pre = searchWord;
        stringstream ss(sentence);
        int i = 0;
        string currWord;
        while(ss>>currWord){
            i++;
            if(comp(currWord)) return i;
        }
        return -1;
    }
};