class TrieNode{
public:
    vector<TrieNode*> next;
    bool isEnd;
    TrieNode(){
        next.resize(26, nullptr);
        isEnd = false;
    }
};

class Trie{
private:
    TrieNode* head;
public:

    Trie(){
        head = new TrieNode();
    }

    void insert(string word){
        TrieNode* curr = head;
        int i = 0;
        while(curr->next[word[i] - 'a'] != nullptr){
            curr = curr->next[word[i++] - 'a'];
            if(i == word.size()) {
                curr->isEnd = true;
                return;
            }
        }
        for(; i<word.size(); i++){
            curr->next[word[i] - 'a'] = new TrieNode();
            curr = curr->next[word[i] - 'a'];
        }
        curr->isEnd = true;
    }

    TrieNode* find(string word){
        TrieNode* curr = head;
        int i = 0;
        while(curr->next[word[i] - 'a'] != nullptr){
            curr = curr->next[word[i++] - 'a'];
            if(i == word.size()) {
                return curr;
            }
        }
        return nullptr;
    }

    vector<string> suggest(string pre, TrieNode* beg) {
        vector<string> ans;
        if (beg == nullptr) return ans;

        function<void(TrieNode*, string)> dfs = [&](TrieNode* node, string word) {
            if (ans.size() == 3) return;
            if (node->isEnd) ans.push_back(word);
            for (int i = 0; i < 26; ++i) {
                if (node->next[i]) {
                    dfs(node->next[i], word + char('a' + i));
                }
            }
        };

        dfs(beg, pre);
        return ans;
    }


    vector<vector<string>> suggestAll(string word){
        vector<vector<string>> ans;
        for(int i = 1; i<=word.size(); i++){
            string pre = word.substr(0, i);
            TrieNode* beg = find(pre);
            ans.push_back(suggest(pre, beg));
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie myTrie;
        for(int i = 0; i<products.size(); i++) myTrie.insert(products[i]);
        vector<vector<string>> ans = myTrie.suggestAll(searchWord);
        return ans;
    }
};