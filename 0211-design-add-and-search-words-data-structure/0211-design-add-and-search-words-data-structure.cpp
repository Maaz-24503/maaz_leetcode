class Node{
public:
    vector<Node*> children;
    bool isEnd;
    Node(){
        isEnd = false;
        children.resize(26, nullptr);
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* curr = root;
        int n = word.size();
        for(char &c : word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool dfs(string &word, int i, Node *curr){
        if(i == word.size()) return curr->isEnd;
        if(word[i] != '.'){
            if(curr->children[word[i] - 'a'] == nullptr) return false;
            else return dfs(word, i+1, curr->children[word[i] - 'a']);
        }
        for(int k = 0; k<26; k++){
            if(curr->children[k] != nullptr && dfs(word, i+1, curr->children[k])) return true;
        }
        return false;
    }

    bool find(string word){
        return dfs(word, 0, root);
    }
};

class WordDictionary {
private:
    Trie* myTrie;
public:
    WordDictionary() {
        myTrie = new Trie();
    }
    
    void addWord(string word) {
        myTrie->insert(word);
    }
    
    bool search(string word) {
        return myTrie->find(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */