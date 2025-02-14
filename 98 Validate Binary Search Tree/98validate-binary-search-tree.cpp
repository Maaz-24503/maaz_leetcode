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
    bool helper(TreeNode* root, long long maxi, long long mini){
        if(root->left == nullptr && root->right == nullptr) return true;
        if(root->left != nullptr){ 
            if(root->left->val <= mini || root->left->val >= maxi || root->left->val >= root->val) return false;
            bool temp = helper(root->left, ((long long)min(maxi, ((long long)root->val))), mini);
            if(!temp) return false;
        }
        if(root->right != nullptr){
            if(root->right->val >= maxi || root->right->val <= mini || root->right->val <= root->val) return false;
            bool temp = helper(root->right, maxi, ((long long)max(mini, ((long long)root->val))));
            if(!temp) return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX + 4LL, INT_MIN - 4LL);
    }
};