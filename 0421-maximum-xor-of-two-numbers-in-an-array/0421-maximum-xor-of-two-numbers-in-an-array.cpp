class Node{
public:
    Node *left, *right;

    Node(){
        left = nullptr;
        right = nullptr;
    }
};

class Trie{
private:
    Node* head;
    static const int bits = 31;

public:
    Trie(){
        head = new Node();
    }

    void insert(int x){
        Node* curr = head;
        for(int i = bits - 1; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(bit == 0){
                if(curr->left == nullptr) curr->left = new Node();
                curr = curr->left;
            }
            else{
                if(curr->right == nullptr) curr->right = new Node();
                curr = curr->right;
            }
        }
    }

    int maxXor(int x){
        Node* curr = head;
        int ans = 0;
        for(int i = bits - 1; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(bit == 1){
                if(curr->left != nullptr){
                    curr = curr->left;
                    ans |= (1 << i);
                }
                else{
                    curr = curr->right;
                }
            }
            else{
                if(curr->right != nullptr){
                    curr = curr->right;
                    ans |= (1 << i);
                }
                else{
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* myTrie = new Trie();
        int ans = 0;
        for(int i = 0; i<n; i++){
            myTrie->insert(nums[i]);
            ans = max(ans, myTrie->maxXor(nums[i]));
        }
        return ans;
    }
};