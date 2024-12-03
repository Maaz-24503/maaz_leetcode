class TrieNode{
public:
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode(){
        child.resize(26);
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->child[word[i] - 'a'] == NULL){
                node->child[word[i] - 'a'] = new TrieNode();
            }
            node = node->child[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(int i = 0; i<word.size(); i++){
            int ind = word[i] - 'a';
            if(curr->child[ind] == NULL) return false;
            curr = curr->child[ind];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(int i = 0; i<prefix.size(); i++){
            int ind = prefix[i] - 'a';
            if(curr->child[ind] == NULL) return false;
            curr = curr->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.Insert(word);
 * bool param_2 = obj.Search(word);
 * bool param_3 = obj.StartsWith(prefix);
 */