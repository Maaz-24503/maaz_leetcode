/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string getString(TreeNode* root){
        if(root->right == nullptr && root->left == nullptr) return to_string(root->val);
        if(root->right == nullptr) return getString(root->left); 
        if(root->left == nullptr) return getString(root->right);
        return getString(root->left) + " " + getString(root->right); 
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getString(root1) == getString(root2);
    }
};