class Node{
public:
    vector<Node*> child;
    bool isEnd;
    Node(){
        isEnd = false;
        child.resize(26, nullptr);
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        int n = word.size();
        for(int i = 0; i<n; i++){
            if(temp->child[word[i] - 'a'] == nullptr) temp->child[word[i] - 'a'] = new Node(); 
            temp = temp->child[word[i] - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        int n = word.size();
        for(int i = 0; i<n; i++){
            if(temp->child[word[i] - 'a'] == nullptr) return false; 
            else temp = temp->child[word[i] - 'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        int n = prefix.size();
        for(int i = 0; i<n; i++){
            if(temp->child[prefix[i] - 'a'] == nullptr) return false; 
            else temp = temp->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */