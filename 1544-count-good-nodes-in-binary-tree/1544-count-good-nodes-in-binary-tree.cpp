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
    int helper(TreeNode* root, int maxi){
        if(root == nullptr) return 0;
        return (maxi <= root->val ? 1 : 0) + helper(root->right, max(maxi, root->val)) + helper(root->left, max(maxi, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};