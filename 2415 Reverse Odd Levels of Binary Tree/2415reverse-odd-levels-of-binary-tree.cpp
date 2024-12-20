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
public:
    void helper(TreeNode* l, TreeNode* r, int iter = 0){
        if(l == nullptr) return;
        if(!(iter % 2)){
            int temp = l->val;
            l->val =  r->val;
            r->val = temp;
        }
        helper(l->right, r->left, iter+1);
        helper(l->left, r->right, iter+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->right, root->left);
        return root;
    }
};